

//int gnd = 10;
int x = A0;
int y = A1;
int z = A2;


void setup() {

  Serial.begin(38400);
  pinMode(x,INPUT);
  pinMode(y,INPUT);
  pinMode(y,INPUT);
 // pinMode(gnd,OUTPUT);
}

void loop() {
  //digitalWrite(gnd,LOW);
  char d;                       //direction
  int x1 = analogRead(x);
  int y1 = analogRead(y);  
  int z1 = analogRead(z); 
  if (x1 <= 300){                   //left
    d = 'l';
   
  }
  else if (x1 >= 400 ){                    //right
    d = 'r';
   
  }
  else if (y1 >= 390 ){                    //forward
    d = 'f';
    
  }
  else if (y1 <= 310){                   //backward 
    d= 'b';
    
  }
  else if (z1 > 410 && y1 > 311 && y1 < 389 && x1 < 399 && x1 > 301){
    d= 's';
    
  }
 // Serial.print(x1);
//  Serial.print("\t");
 // Serial.print(y1);
 //  Serial.print("\t");
  // Serial.println(z1);
// Serial.println(d);
if (Serial.available() > 0)
{
 // Serial.print("Connected");
 // Serial.print("\n");
  Serial.write(d);
}
//else
//Serial.print("Not connected");

  
}

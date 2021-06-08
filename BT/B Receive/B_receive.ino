#include <SoftwareSerial.h>

int motor1 = 9;
int motor2 = 10;
int motor3 = 3;
int motor4 = 4;
int shield = 2;
char a;

void setup() {
  Serial.begin(38400);
        
  Serial.println("Motor test!");
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  pinMode(shield,OUTPUT);
  digitalWrite(shield,HIGH);
  }
 

void loop() {
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,LOW);
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,LOW);
  
 if(Serial.available() > 0)
 {
  Serial.print("Conn");
  a = Serial.read();
 }
    Serial.print("\n");
    Serial.print("LOOk At ThIs --->");
    Serial.println(a);
    if(a == 'f'){
      Serial.println("forward");
      digitalWrite(motor1,HIGH);
      digitalWrite(motor2,LOW);
      digitalWrite(motor3,HIGH);
      digitalWrite(motor4,LOW);
    }
    if(a == 'b'){
      Serial.println("backward"); 
      digitalWrite(motor1,LOW);
      digitalWrite(motor2,HIGH);
      digitalWrite(motor3,LOW);
      digitalWrite(motor4,HIGH);
    }
    if(a == 'l'){
      Serial.println("left");
      digitalWrite(motor1,LOW);
      digitalWrite(motor2,HIGH);
      digitalWrite(motor3,HIGH);
      digitalWrite(motor4,LOW);
    }
    if( a == 'r'){
      Serial.println("right");
      digitalWrite(motor1,HIGH);
      digitalWrite(motor2,LOW);
      digitalWrite(motor3,LOW);
      digitalWrite(motor4,HIGH);
    }
    if(a == 's'){
      Serial.println("stay");
      digitalWrite(motor1,LOW);
      digitalWrite(motor2,LOW);
      digitalWrite(motor3,LOW);
      digitalWrite(motor4,LOW);
    }
    delay(20);
}

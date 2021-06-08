#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

int water = 5;
int fire = 6;
int motor1 = 9;
int motor2 = 10;
int motor3 = 3;
int motor4 = 4;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
  Serial.begin(9600);           
  Serial.println("Motor test!");
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  pinMode(fire,INPUT);
  pinMode(water,OUTPUT);
}

void loop() {
 int m = digitalRead(fire);
  if (m == 0)
  {
    digitalWrite(water,HIGH);
    Serial.println("m");
   Serial.println("ice and fire"); 
  }
  else{
     digitalWrite(water,LOW);
  }


  
  if (radio.available()) { 
    char d = 'f';
    radio.read(&d, sizeof(d));
    Serial.println(d);
    if(d=='f'){
      Serial.println("forward");
      digitalWrite(motor1,HIGH);
      digitalWrite(motor2,LOW);
      digitalWrite(motor3,HIGH);
      digitalWrite(motor4,LOW);
    }
    if(d=='b'){
      Serial.println("backward"); 
      digitalWrite(motor1,LOW);
      digitalWrite(motor2,HIGH);
      digitalWrite(motor3,LOW);
      digitalWrite(motor4,HIGH);
    }
    if(d=='l'){
      Serial.println("right");
      digitalWrite(motor1,LOW);
      digitalWrite(motor2,HIGH);
      digitalWrite(motor3,HIGH);
      digitalWrite(motor4,LOW);
    }
    if(d=='r'){
      Serial.println("left");
      digitalWrite(motor1,HIGH);
      digitalWrite(motor2,LOW);
      digitalWrite(motor3,LOW);
      digitalWrite(motor4,HIGH);
    }
    if(d==' '){
      Serial.println("stay");
      digitalWrite(motor1,LOW);
      digitalWrite(motor2,LOW);
      digitalWrite(motor3,LOW);
      digitalWrite(motor4,LOW);
     
    }
    delay(1000);
  }

  
}

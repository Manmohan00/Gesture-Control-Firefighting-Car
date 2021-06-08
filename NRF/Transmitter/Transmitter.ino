
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

MPU6050 mpu6050(Wire);

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  radio.stopListening();
  mpu6050.update();
  float x,y,z;
  char d;                       //direction
  x = mpu6050.getAngleX();
  y = mpu6050.getAngleY();
  if (x<-11 && y<8){                   //left
    d='l';
  }
  else if (x>25 && y>-25){                    //right
    d='r';
  }
  else if (y>8 && x>-10){                    //forward
    d='f';
  }
  else if (y<-25 && x<25){                   //backward 
    d='b';
  }
  else{
    d=' ';
  }
  Serial.println(x);
  Serial.println(d);
  radio.write(&d, sizeof(d));
}

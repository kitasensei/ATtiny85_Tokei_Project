//ARDINO NANO
//TM1637接続ピン番号:DIOpin=2(デジタルピン2) CLKpin=3（デジタルピン3）
//I2c通信ではないため、専用ピンがそれぞれに必要
//DS3231接続ピン番号:DIOpin=A4 CLKpin=A5（ハードI2cピンを使用）このスケッチでは未使用

// #include <TM1637Display.h>
#define CLK 2
#define DIO 3
//TM1637Display display(CLK, DIO);
//#include <Wire.h>
#include <Arduino.h> 

void setup(){
  //Wire.begin();      //マスターで接続
  //Serial.begin(9600);//シリアル通信スタート
  //display.setBrightness(3);//0~7 7が一番明るい
  pinMode(CLK,OUTPUT);
  pinMode(DIO,OUTPUT);
  pinMode(CLK,HIGH);
  pinMode(DIO,HIGH);
  delay(500);
}

void loop() {
//display.showNumberDec(7777);

//START signal

digitalWrite(DIO,HIGH);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);
digitalWrite(DIO,LOW);//DIO 1st
delayMicroseconds(5);
digitalWrite(CLK,LOW);//CLK 2nd
delayMicroseconds(5);

//command 1 (DATA command)

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B0 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B1 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B2 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B3 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B4 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B5 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,HIGH);//B6 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B7 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

//ACK
pinMode(DIO, INPUT);
delayMicroseconds(10);
digitalWrite(CLK,LOW);
delayMicroseconds(5);
if (digitalRead(DIO) != 0 ) {
  Serial.println("ACK fails");
}
else{
  pinMode(DIO,OUTPUT);
  delayMicroseconds(10);
  digitalWrite(CLK,HIGH);
  delayMicroseconds(5);
}

//command 2 (ADDRESS)

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B0 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B1 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B2 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B3 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B4 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B5 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,HIGH);//B6 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,HIGH);//B7 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

//ACK
pinMode(DIO, INPUT);
delayMicroseconds(10);
digitalWrite(CLK,LOW);
delayMicroseconds(5);
if (digitalRead(DIO) != 0 ) {
  Serial.println("ACK fails");
}
else{
  pinMode(DIO,OUTPUT);
  delayMicroseconds(10);
  digitalWrite(CLK,HIGH);
  delayMicroseconds(5);
}

//7seg DATA 

digitalWrite(CLK,LOW);
digitalWrite(DIO,HIGH);//B0 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,HIGH);//B1 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,HIGH);//B2 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B3 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,HIGH);//B4 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,HIGH);//B5 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,HIGH);//B6 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B7 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

//ACK
pinMode(DIO, INPUT);
delayMicroseconds(10);
digitalWrite(CLK,LOW);
delayMicroseconds(5);
if (digitalRead(DIO) != 0 ) {
  Serial.println("ACK fails");
}
else{
  pinMode(DIO,OUTPUT);
  delayMicroseconds(10);
  digitalWrite(CLK,HIGH);
  delayMicroseconds(5);
}

//command 3 (0x01001010) displayON LEVEL3

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B0 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,HIGH);//B1 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B2 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,HIGH);//B3 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B4 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B5 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,HIGH);//B6 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B7 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);

//ACK
pinMode(DIO, INPUT);
delayMicroseconds(10);
digitalWrite(CLK,LOW);
delayMicroseconds(5);
if (digitalRead(DIO) != 0 ) {
  Serial.println("ACK fails");
}
else{
  pinMode(DIO,OUTPUT);
  delayMicroseconds(10);
  digitalWrite(CLK,HIGH);
  delayMicroseconds(5);
}

//STOP signal
digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK 1st
delayMicroseconds(5);
digitalWrite(DIO,HIGH);//DIO 2nd
delayMicroseconds(5);

delay(1000);
}
//ARDINO NANO
//TM1637接続ピン番号:KIDIOpin=2(デジタルピン2) KICLKpin=3（デジタルピン3）
//I2c通信ではないため、専用ピンがそれぞれに必要
//DS3231接続ピン番号:KIDIOpin=A4 KICLKpin=A5（ハードI2cピンを使用）このスケッチでは未使用
#include <Arduino.h> 
// #include <TM1637Display.h>
#define KICLK 5
#define KIDIO 6
//TM1637Display display(KICLK, KIDIO);
//#include <Wire.h>

void setup(){
  //Wire.begin();      //マスターで接続
  Serial.begin(9600);//シリアル通信スタート
  //display.setBrightness(3);//0~7 7が一番明るい
  pinMode(KICLK,OUTPUT);
  pinMode(KIDIO,OUTPUT);
  delayMicroseconds(2);
  digitalWrite(KICLK,HIGH);
  digitalWrite(KIDIO,HIGH);
  delay(500);
}


void loop() {
//display.showNumberDec(7777);

//START signal
//--------------------
digitalWrite(KICLK,HIGH);
digitalWrite(KIDIO,HIGH);
delayMicroseconds(2);
digitalWrite(KIDIO,LOW);//KIDIO LOW
delayMicroseconds(2);
digitalWrite(KICLK,LOW);
delayMicroseconds(2);
//--------------------

//command 1 (DATA command) LSB 1st 0x 0100 0000
  
digitalWrite(KIDIO,LOW);//B0 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse1
delayMicroseconds(2);
digitalWrite(KICLK,LOW);
delayMicroseconds(2);

digitalWrite(KIDIO,LOW);//B1 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse2
delayMicroseconds(2);
digitalWrite(KICLK,LOW);
delayMicroseconds(2);

digitalWrite(KIDIO,LOW);//B2 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse3
delayMicroseconds(2);
digitalWrite(KICLK,LOW);
delayMicroseconds(2);

digitalWrite(KIDIO,LOW);//B3 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse4
delayMicroseconds(2);
digitalWrite(KICLK,LOW);
delayMicroseconds(2);

digitalWrite(KIDIO,LOW);//B4 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse5
delayMicroseconds(2);
digitalWrite(KICLK,LOW);
delayMicroseconds(2);

digitalWrite(KIDIO,LOW);//B5 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse6
delayMicroseconds(2);
digitalWrite(KICLK,LOW);
delayMicroseconds(2);

digitalWrite(KIDIO,HIGH);//B6 1
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse7
delayMicroseconds(2);
digitalWrite(KICLK,LOW);
delayMicroseconds(2);

digitalWrite(KIDIO,LOW);//B7 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse8
delayMicroseconds(2);

//ACK rev1.9
//--------------------  
digitalWrite(KICLK,LOW); // まずKICLKをLOWにして合図
digitalWrite(KIDIO,LOW);
pinMode(KIDIO, INPUT); // その後、KIDIOを入力モードに切り替える
delayMicroseconds(2);//ACK 信号待ち時間
if (digitalRead(KIDIO) == HIGH ) {
Serial.println("ACK FALES 1"); 
}
else{
  pinMode(KIDIO,OUTPUT);
  delayMicroseconds(2);
  digitalWrite(KICLK,HIGH);
  delayMicroseconds(2);
  digitalWrite(KICLK,LOW);
  delayMicroseconds(2);
}
//--------------------  

//STOP signal
//--------------------
digitalWrite(KICLK,HIGH);
digitalWrite(KIDIO,HIGH);
//--------------------

//START signal
//--------------------
digitalWrite(KIDIO,LOW);
digitalWrite(KICLK,LOW);

//--------------------

//command 2 (Start ADDRESS) LSB 1st 0x 1100 0000

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B0 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse1
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B1 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse2
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B2 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse3
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B3 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse4
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B4 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse5
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B5 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse6
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,HIGH);//B6 1
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse7
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,HIGH);//B7 1
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse

//ACK rev1.8
//--------------------  
digitalWrite(KICLK,LOW); // まずKICLKをLOWにして合図
pinMode(KIDIO, INPUT); // その後、KIDIOを入力モードに切り替える
delayMicroseconds(2);//ACK 信号待ち時間
if (digitalRead(KIDIO) == HIGH ) {
Serial.println("ACK FALES 2"); 
}
else{
  pinMode(KIDIO,OUTPUT);
  digitalWrite(KICLK,HIGH);
  digitalWrite(KICLK,LOW);
}
//--------------------  


//7seg DATA 7 0x 0000 0100

digitalWrite(KICLK,LOW);  
digitalWrite(KIDIO,LOW);//B0 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse1
delayMicroseconds(5);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B1 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse2
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,HIGH);//B2 1
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse3
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B3 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse4
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B4 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse5
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B5 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse6
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B6 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse7
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B7 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse8

//ACK rev1.7
//--------------------  
digitalWrite(KICLK,LOW); // まずKICLKをLOWにして合図
pinMode(KIDIO, INPUT); // その後、KIDIOを入力モードに切り替える
delayMicroseconds(5);//ACK 信号待ち時間
if (digitalRead(KIDIO) == HIGH ) {
}
else{
  pinMode(KIDIO,OUTPUT);
  delayMicroseconds(5);
  digitalWrite(KICLK,HIGH);
  delayMicroseconds(2);
  digitalWrite(KICLK,LOW);
  delayMicroseconds(2);
}
//--------------------  

//STOP signal
//--------------------
digitalWrite(KICLK,LOW);
delayMicroseconds(2);
digitalWrite(KIDIO,LOW);
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);
delayMicroseconds(2);
digitalWrite(KIDIO,HIGH);
//--------------------

//START signal
//--------------------
digitalWrite(KICLK,HIGH);
digitalWrite(KIDIO,HIGH);
delayMicroseconds(2);
digitalWrite(KIDIO,LOW);//KIDIO LOW
//--------------------  


//command 3 (0x 0100 1010) displayON LEVEL3
  
digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B0 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse1
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,HIGH);//B1 
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse2
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B2 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse3
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,HIGH);//B3 1
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse4
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B4 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse5
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,LOW);//B5 0
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse6
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,HIGH);//B6 1
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse7
delayMicroseconds(2);

digitalWrite(KICLK,LOW);
digitalWrite(KIDIO,HIGH);//B7 1
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);//KICLK pulse8

//ACK rev1.7
//--------------------  
digitalWrite(KICLK,LOW); // まずKICLKをLOWにして合図
pinMode(KIDIO, INPUT); // その後、KIDIOを入力モードに切り替える
delayMicroseconds(5);//ACK 信号待ち時間
if (digitalRead(KIDIO) == HIGH ) {
}
else{
  pinMode(KIDIO,OUTPUT);
  delayMicroseconds(5);
  digitalWrite(KICLK,HIGH);
  delayMicroseconds(2);
  digitalWrite(KICLK,LOW);
  delayMicroseconds(2);
}
//--------------------  

//STOP signal
//--------------------
digitalWrite(KICLK,LOW);
delayMicroseconds(2);
digitalWrite(KIDIO,LOW);
delayMicroseconds(2);
digitalWrite(KICLK,HIGH);
delayMicroseconds(2);
digitalWrite(KIDIO,HIGH);
//--------------------


delay(1000);
}

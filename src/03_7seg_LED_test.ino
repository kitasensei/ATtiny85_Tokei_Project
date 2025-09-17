//ARDINO NANO
//TM1637接続ピン番号:DIOpin=2(デジタルピン2) CLKpin=3（デジタルピン3）
//I2c通信ではないため、専用ピンがそれぞれに必要
//DS3231接続ピン番号:DIOpin=A4 CLKpin=A5（ハードI2cピンを使用）このスケッチでは未使用
#include <Arduino.h> 
// #include <TM1637Display.h>
#define CLK 5
#define DIO 6
//TM1637Display display(CLK, DIO);
//#include <Wire.h>

void setup(){
  //Wire.begin();      //マスターで接続
  Serial.begin(9600);//シリアル通信スタート
  //display.setBrightness(3);//0~7 7が一番明るい
  pinMode(CLK,OUTPUT);
  pinMode(DIO,OUTPUT);
  delayMicroseconds(5);
  pinMode(CLK,HIGH);
  pinMode(DIO,HIGH);
  delay(500);
  Serial.println("setup OK");
}


void loop() {
//display.showNumberDec(7777);

//START signal
//--------------------
digitalWrite(CLK,HIGH);
digitalWrite(DIO,HIGH);
delayMicroseconds(5);
digitalWrite(DIO,LOW);//DIO LOW
Serial.println("1st start signal OK");
//--------------------

//command 1 (DATA command) LSB 1st 0x 0100 0000
  
digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B0 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse1
delayMicroseconds(5);

digitalWrite(CLK,LOW);  
digitalWrite(DIO,LOW);//B1 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse2
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B2 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse3
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);
  
digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B3 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse4
delayMicroseconds(5);

digitalWrite(CLK,LOW);  
digitalWrite(DIO,LOW);//B4 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse5
delayMicroseconds(5);
  
digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B5 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse6
delayMicroseconds(5);

digitalWrite(CLK,LOW);  
digitalWrite(DIO,HIGH);//B6 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse7
delayMicroseconds(5);

digitalWrite(CLK,LOW);
digitalWrite(DIO,LOW);//B7 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse8

//ACK rev1.6
digitalWrite(CLK,LOW); // まずCLKをLOWにして合図
pinMode(DIO, INPUT); // その後、DIOを入力モードに切り替える
delayMicroseconds(10);//ACK 信号待ち時間
if (digitalRead(DIO) != 0 ) {
  Serial.println("ACK fails");
}
else{
  pinMode(DIO,OUTPUT);
  delayMicroseconds(10);
  digitalWrite(CLK,HIGH);
  delayMicroseconds(5);
  digitalWrite(CLK,LOW);
  delayMicroseconds(5);
}
Serial.println("command1 OK");

//STOP

digitalWrite(CLK,LOW);
delayMicroseconds(5);
digitalWrite(DIO,LOW);
delayMicroseconds(5);
digitalWrite(CLK,HIGH);
delayMicroseconds(5);
digitalWrite(DIO,HIGH);




//command 2 (Start ADDRESS) LSB 1st 0x 1100 0000

digitalWrite(DIO,LOW);//B0 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse1
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B1 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse2
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B2 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse3
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B3 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse4
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B4 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse5
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B5 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse6
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,HIGH);//B6 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse7
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,HIGH);//B7 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse8
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

//アドレス送信後はACK確認のみ

digitalWrite(DIO,HIGH);//B7 1
digitalWrite(CLK,HIGH);//CLK pulse8
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

//ACK rev1.4
digitalWrite(CLK,LOW); // まずCLKをLOWにして合図
delayMicroseconds(5);
pinMode(DIO, INPUT); // その後、DIOを入力モードに切り替える
delayMicroseconds(100);//ACK 信号待ち時間
if (digitalRead(DIO) != 0 ) {
  Serial.println("ACK fails");
}
else{
  pinMode(DIO,OUTPUT);
  delayMicroseconds(10);
  digitalWrite(CLK,HIGH);
  delayMicroseconds(5);
  digitalWrite(CLK,LOW);
  delayMicroseconds(5);
}
Serial.println("command2 OK");


//7seg DATA 7 0x 0000 0100

digitalWrite(DIO,LOW);//B0 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse1
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B1 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse2
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,HIGH);//B2 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse3
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B3 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse4
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B4 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse5
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B5 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse6
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B6 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse7
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B7 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse8
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

//セグメントデーター送信後はACKのあとスタート信号

//ACK rev1.4
digitalWrite(CLK,LOW); // まずCLKをLOWにして合図
delayMicroseconds(5);
pinMode(DIO, INPUT); // その後、DIOを入力モードに切り替える
delayMicroseconds(100);//ACK 信号待ち時間
if (digitalRead(DIO) != 0 ) {
  Serial.println("ACK fails");
}
else{
  pinMode(DIO,OUTPUT);
  delayMicroseconds(10);
  digitalWrite(CLK,HIGH);
  delayMicroseconds(5);
  digitalWrite(CLK,LOW);
  delayMicroseconds(5);
}

//START next command

digitalWrite(CLK,HIGH);  //START
delayMicroseconds(5);    //  ↓
digitalWrite(DIO,HIGH);  //  ↓
delayMicroseconds(5);    //START
digitalWrite(DIO,LOW);   //STOP
delayMicroseconds(5);    //  ↓
digitalWrite(CLK,LOW);   //  ↓  
delayMicroseconds(5);    //STOP


Serial.println("7seg data OK");

//command 3 (0x 0100 1010) displayON LEVEL3

digitalWrite(DIO,LOW);//B0 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse1
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,HIGH);//B1 
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse2
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B2 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse3
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,HIGH);//B3 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse4
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B4 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse5
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,LOW);//B5 0
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse6
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,HIGH);//B6 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse7
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

digitalWrite(DIO,HIGH);//B7 1
delayMicroseconds(5);
digitalWrite(CLK,HIGH);//CLK pulse8
delayMicroseconds(5);
digitalWrite(CLK,LOW);
delayMicroseconds(5);

//ACK rev1.4
digitalWrite(CLK,LOW); // まずCLKをLOWにして合図
delayMicroseconds(5);
pinMode(DIO, INPUT); // その後、DIOを入力モードに切り替える
delayMicroseconds(100);//ACK 信号待ち時間
if (digitalRead(DIO) != 0 ) {
  Serial.println("ACK fails");
}
else{
  pinMode(DIO,OUTPUT);
  delayMicroseconds(10);
  digitalWrite(CLK,HIGH);
  delayMicroseconds(5);
  digitalWrite(CLK,LOW);
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

Serial.println("final command OK");

delay(1000);
}

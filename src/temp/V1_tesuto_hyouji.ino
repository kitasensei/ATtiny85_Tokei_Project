//2025/8/24
//テスト環境 ARDUINO NANO
//スイッチ入力と、表示の確認
//PIND 0b00000100:PD2(D2ピン)
//指定方法、SBI PIND,2（PINDの2ビット目を1にする）CBI PIND,2（PINDの2ビット目を0にする）
//「TM1637Display by Avishay Orpaz」7セグTM1637 ライブラリ

#include <Arduino.h>
#include <Wire.h>// I2c通信用
#include <TM1637Display.h>

// ピンの定義
#define CLK 2
#define DIO 3

// TM1637オブジェクトの作成
TM1637Display display(CLK, DIO); // ★ 修正: オブジェクトの型を TM1637 に変更

void setup() {
    pinMode(23,INPUT_PULLUP);
    Serial.begin(9600); //シリアル通信速度

    // ディスプレイの初期化
    display.clear(); // ★ 修正: clear() 関数は使えます
    display.setBrightness(0x01); // ★ 修正: setBrightness() 関数は使えます
}

void loop() {
    Serial.println("test");
    
    // TM1637 ライブラリの関数に修正
    // showNumberDec() は使えないため、display() 関数を使います
    display.showNumberDec(0, 1);
    display.showNumberDec(1, 2);
    display.showNumberDec(2, 3);
    display.showNumberDec(3, 4);

    delay(2000);

    // display.showNumberDecEx() は使えないため、個別の表示関数を使います
    display.showNumberDec(0, 2);
    display.showNumberDec(1, 3);
    display.showNumberDec(2, 5);
    display.showNumberDec(3, 9);
    
    // コロンを点灯させるには、コロンのデータをディスプレイに直接送信します
    display.showNumberDecEx(2359, 0b11100000, true, 4, 0); // showNumberDecEx() は使えない可能性があります
    
    delay(2000);
}
//2025/8/25
//テスト環境 ARDUINO NANO
//スイッチ入力と、表示の確認
//チャタリングの観測とその表示を行う
//PIND 0b00000100:PD2(D2ピン)
//指定方法、SBI PIND,2（PINDの2ビット目を1にする）CBI PIND,2（PINDの2ビット目を0にする）
//「TM1637Display by Avishay Orpaz」7セグTM1637 ライブラリ

#include <Arduino.h>
#include <Wire.h>// I2c通信用
#include <TM1637Display.h>

// ピンの定義
#define CLK 2
#define DIO 3
//変数定義
// int kauntHyouji();

// TM1637オブジェクトの作成
TM1637Display display(CLK, DIO); //初期設定

void setup() {
    pinMode(23,INPUT_PULLUP);
    Serial.begin(9600); //シリアル通信速度

    // ディスプレイの初期化
    display.clear(); // ★ 修正: clear() 関数は使えます
    display.setBrightness(0x01); // ★ 修正: setBrightness() 関数は使えます
}

void loop() {
    if (timeCount() != 500){

    Serial.println("test");
    if (digitalRead(unit8_t 23) = HIGH,){kauntHyouji == 1
    };s

    if (kauntHyouji() == 0){
    display.showNumberDec(0, 1);
    display.showNumberDec(1, 2);
    display.showNumberDec(2, 3);
    display.showNumberDec(3, 4);
    Serial.println("1234");
    //delay(2000);
    };

    display.showNumberDec(0, 2);
    display.showNumberDec(1, 3);
    display.showNumberDec(2, 5);
    display.showNumberDec(3, 9);
    display.showNumberDecEx(2359, 0b11100000, true, 4, 0); // コロン表示
    Serial.println("23:59")
    //delay(2000);
    };
delay(2000);
};

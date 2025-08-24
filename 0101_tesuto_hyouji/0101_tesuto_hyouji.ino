//2025/8/24
//テスト環境 ARDUINO NANO
//スイッチ入力と、表示の確認
//PIND 0b00000100:PD2(D2ピン)
//指定方法、SBI PIND,2（PINDの2ビット目を1にする）CBI PIND,2（PINDの2ビット目を0にする）
//「TM1637Display by Avishay Orpaz」7セグTM1637 ライブラリ

#include <Wire.h>// I2c通信用
#include <TM1637Display.h>

// ピンの定義
#define CLK 2   //ARDUINO_NANO=D2,ATtiny85=pin2
#define DIO 3   //ARDUINO_NANO=D3,ATtiny85=Pin3

// TM1637Displayオブジェクトの作成
TM1637Display display(CLK, DIO);

void setup() {
    pinMode(23,INPUT_PULLUP);   //入力ボタン設定
    Serial.begin(9600); //シリアル通信速度
    // ディスプレイの初期化
    display.clear();
    display.setBrightness(0x01); // 明るさ設定
}

void loop() {
   Serial.println("test");
    // 数字の表示
    display.showNumberDec(1234, false); // "1234" を表示
    delay(2000);

    display.showNumberDec(5678, false, 4, 0); // "5678" を表示
    delay(2000);

    // 時刻表示
    display.showNumberDecEx(2359, 0b11100000, true, 4, 0); // コロンを点灯させて"23:59"を表示
    delay(2000);
}
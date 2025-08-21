// 名称：ATtiny85 時計
// 使用パーツ
// ATtiny85　　マイコン
// DS3231　　　リアルタイムクロックモジュール（RTC）
// TM1637　　　７セグメント４桁
// ピン配置
// ボタン  スイッチ	PB0-ピン 5 ---設定用ボタン　 長押しで設定モード及び項目移動。短押しで設定および表示切替。
// DS3231  SDA	   PB1-ピン 6	---Software I2C用(ピン定義は自動)
// DS3231	 SCL	   PB2-ピン 7	---Software I2C用(ピン定義は自動)
// TM1637	 DIO	   PB3-ピン	2 ---７セグメント I2C用
// TM1637	 CLK	   PB4-ピン	3 ---７セグメント I2C用 
// スイッチ用プルアップ抵抗 ---10KΩ

#include <Wire.h>// I2c通信用
#include "RTClib.h"//(Adafruit RTClib)
#include <TM1637Display.h>

// TM1637モジュールのピン定義
const int DIO_PIN = 2; // DIOピン
const int CLK_PIN = 3; // CLKピン


// TM1637Displayオブジェクトを作成する
TM1637Display display(CLK_PIN, DIO_PIN);

// RTCオブジェクトを作成します
RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);//シリアル通信開始
  Wire.begin();// I2C通信を開始します
  if (!rtc.begin()) {// RTCモジュールがI2Cバス上に存在するか確認します
    Serial.println("RTCが見つかりません。");//シリアルにエラー表示
    while (1); // 停止
  }

  if (rtc.lostPower()) {// もしRTCが時間計測を停止していたら、時刻を設定します
    Serial.println("RTCが電源を失ったので、時刻をリセットします。");//シリアルにメッセージ
    rtc.adjust(DateTime(2025, 1, 1, 1, 0, 0));// 時間の再設定
  }
  display.setBrightness(1);// ディスプレイの明るさを設定 (0:暗い 〜 7:明るい)
  display.showNumberDec(8888, 0b01000000, true);// 起動時にTM1637に「88:88」と表示して動作確認
  delay(1000);
}

//グローバル変数
const int buttonPin = 5; // ボタンを接続するピン
int lastButtonState = HIGH;//プルアップ
unsigned long buttonPressTime = 0; // ボタンが押された時刻
//状態監視変数
int nomal_mode = 1//通常モード
int set_mode = 0//設定モード
int button_s = 0//ボタン短押しフラグ
int button_l = 0//ボタン長押しフラグ

void loop() {
 
  //ボタン判定
  // ボタンが押された瞬間
  if (buttonState == LOW && lastButtonState == HIGH) {
    buttonPressTime = millis(); // 現在の時刻を記録
  }

  // ボタンが離された瞬間
  if (buttonState == HIGH && lastButtonState == LOW) {
    // 押されていた時間を計算
    unsigned long pressDuration = millis() - buttonPressTime;

    // 短押し判定 (0.5秒未満)
    if (pressDuration < 500) {
      button_s = 1;//ボタン短押しフラグ
    }
    // 長押し判定 (1秒以上)
    else if (pressDuration >= 1000) {
      button_l = 1;//ボタン長押しフラグ
    }
  }



//ボタン短押し（通常時）
if button_s == 1
void handleShortPress() {
 }
}

//ボタン長押し（設定モード）
void handleLongPress() {
}



  DateTime now = rtc.now();// RTCから現在の日時を読み出します
  display.showNumberDec(now.hour() * 100 + now.minute(), 0b01000000, true);
  delay(1000);//1秒ごとに表示
  
}

//
//チャタリングカウントテスト
//
//
//
#include <Arduino.h>
#include <Wire.h>
#include <TM1637Display.h>

// ピンの定義
#define CLK 2
#define DIO 3
#define BUTTON_PIN 12 // ボタンを接続するピン
#define LED_PIN 13    // Arduino Nano の内蔵 LED ピン

// TM1637 オブジェクトの作成
TM1637Display display(CLK, DIO);

// 変数定義
unsigned long startTime = 0;
int changeCount = 0; // 状態変化の回数
int lastButtonState = HIGH;
bool isMeasuring = false;

const unsigned long DELAY_BEFORE_MEASURE = 5000; // 計測開始までの待ち時間（5秒）
const int MAX_COUNT = 10;                         // 終了するカウント数

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);

  // ディスプレイの初期設定
  display.clear();
  display.setBrightness(0x0a);

  startTime = millis();
  Serial.println("Wait 5 seconds to start measurement...");
}

void loop() {
  // 1. プログラム開始から5秒経過したら計測開始
  if (!isMeasuring && (millis() - startTime) >= DELAY_BEFORE_MEASURE) {
    digitalWrite(LED_PIN, HIGH);
    isMeasuring = true;
    Serial.println("--- Measurement Started! ---");
    Serial.println("Press the button to count.");
  }

  // 3. ボタンの状態変化をカウント
  if (isMeasuring && changeCount < MAX_COUNT) {
    int currentButtonState = digitalRead(BUTTON_PIN);

    // 状態が前回と異なる場合
    if (currentButtonState != lastButtonState) {
      changeCount++;
      Serial.print("Button state changed. Count: ");
      Serial.println(changeCount);
      display.showNumberDec(changeCount);
    }
    lastButtonState = currentButtonState;
  }
  
  // 4. カウントが10に達したら終了
  if (changeCount >= MAX_COUNT) {
    isMeasuring = false;
    digitalWrite(LED_PIN, LOW);
    
    Serial.println("--- Measurement Ended ---");
    Serial.print("Final Count: ");
    Serial.println(changeCount);
    Serial.println("Subtract your button presses to find the chattering count.");
    
    // プログラムを停止
    while(true);
  }
}
//
//チャタリングカウント
//
//
//
#include <Arduino.h>
#include <Wire.h>
#include <TM1637Display.h>

// ピンの定義
#define CLK 2
#define DIO 3
#define BUTTON_PIN 12

// TM1637オブジェクトの作成
TM1637Display display(CLK, DIO);

// 変数定義
int lastButtonState = HIGH; 
long lastChangeTime = 0;
int chatteringCount = 0;
long debounceDelay = 1;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);

  // ディスプレイの初期設定
  display.clear();
  display.setBrightness(0x0a);
  Serial.println("Ready to detect chattering...");
}

void loop() {
  // 現在のボタンの状態を読み込む
  int currentButtonState = digitalRead(BUTTON_PIN);

  // 状態が前回と異なる場合
  if (currentButtonState != lastButtonState) {
    long currentTime = millis();
    // 前回の状態変化からdebounceDelayよりも短い時間で変化した場合、チャタリングと見なす
    if ((currentTime - lastChangeTime) < debounceDelay) {
      chatteringCount++;
      Serial.print("Chattering detected: ");
      Serial.println(chatteringCount);
      // ディスプレイにチャタリング回数を表示
      display.showNumberDec(chatteringCount);
    }
    // 状態が変化した時間を更新
    lastChangeTime = currentTime;
  }
  
  // 最後に今回の状態を保存
  lastButtonState = currentButtonState;

  // ボタンが押されていない状態（HIGH）がdebounceDelay以上続いたら、カウントをリセット
  if (currentButtonState == HIGH && (millis() - lastChangeTime) > debounceDelay) {
    if (chatteringCount > 0) {
      Serial.println("--- Chattering period ended. Resetting count. ---");
      chatteringCount = 0;
      display.clear();
    }
  }
}
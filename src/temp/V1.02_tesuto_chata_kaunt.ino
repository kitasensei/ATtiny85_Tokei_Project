#include <Arduino.h>
#include <Wire.h>
#include <TM1637Display.h>

// ピンの定義
#define CLK 2
#define DIO 3
#define BUTTON_PIN 23 

// TM1637オブジェクトの作成
TM1637Display display(CLK, DIO);

// 変数定義
int lastState;       // 前回のボタンの状態を記憶
int debounceCount;   // チャタリングをカウントする変数
long lastDebounceTime = 0; // 最後に状態が変わった時刻
long debounceDelay = 5;    // チャタリングと見なす遅延時間 (ms)

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(9600);
    
    // ディスプレイの初期設定
    display.clear();
    display.setBrightness(0x0a);
    
    // 初期のボタン状態を読み込む
    lastState = digitalRead(BUTTON_PIN);
    debounceCount = 0;
}

void loop() {
    // 現在のボタンの状態を読み込む
    int currentState = digitalRead(BUTTON_PIN);

    // 前回の状態と現在の状態が異なる場合
    if (currentState != lastState) {
        // 状態が変化した時刻を記録
        lastDebounceTime = millis();
    }
    
    // 短い遅延時間内に状態が何度も変化する場合、チャタリングと見なす
    // ※ この if 文がチャタリングを検出する肝です
    if ((millis() - lastDebounceTime) < debounceDelay) {
        // チャタリングの回数をカウント
        debounceCount++;
        
        // カウントをディスプレイとシリアルに表示
        display.showNumberDec(debounceCount);
        Serial.print("Chattering detected: ");
        Serial.println(debounceCount);

        // ※ 実際のボタンのON/OFFではないので、この時点では何も表示しない
    }
    
    // 状態が安定し、かつボタンが押された（LOWになった）場合
    if ((millis() - lastDebounceTime) > debounceDelay && currentState == LOW) {
        // ボタンが確定的に押されたことを示す
        Serial.println("--- Button Pressed ---");
        // チャタリングのカウントをリセット
        debounceCount = 0;
    }

    // 最後に、今回の状態を次回の比較のために保存
    lastState = currentState;
}
//最新スケッチ

#include <Arduino.h>

#define CLK 5
#define DIO 6

// 1バイトを送信する関数 (シンプルで堅牢なバージョン)
bool writeByte(uint8_t data) {
    for (uint8_t i = 0; i < 8; i++) {
        digitalWrite(CLK, LOW);
        delayMicroseconds(50);
        
        // ビットが1の場合、DIOをHIGHに
        if ((data >> i) & 0x01) {
            digitalWrite(DIO, HIGH);
        } else {
            // ビットが0の場合、DIOをLOWに
            digitalWrite(DIO, LOW);
        }
        
        delayMicroseconds(50); // データ安定のための待ち時間
        digitalWrite(CLK, HIGH);
        delayMicroseconds(50);
    }
    
    // ACKの確認 (処理はこれまでと同じ)
    digitalWrite(CLK, LOW);
    delayMicroseconds(10);
    pinMode(DIO, INPUT);
    delayMicroseconds(10);
    bool ack = (digitalRead(DIO) == LOW);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(10);
    pinMode(DIO, OUTPUT);
    digitalWrite(DIO, HIGH);
    
    return ack;
}

// START信号
void start() {
    digitalWrite(CLK, HIGH);
    digitalWrite(DIO, HIGH);
    delayMicroseconds(10);
    digitalWrite(DIO, LOW);
    delayMicroseconds(10);
    digitalWrite(CLK, LOW);
    delayMicroseconds(10);
}

// STOP信号
void stop() {
    digitalWrite(CLK, LOW);
    digitalWrite(DIO, LOW);
    delayMicroseconds(10);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(10);
    digitalWrite(DIO, HIGH);
    delayMicroseconds(10);
}

void setup() {
    Serial.begin(9600);
    pinMode(CLK, OUTPUT);
    pinMode(DIO, OUTPUT);
    digitalWrite(CLK, HIGH);
    digitalWrite(DIO, HIGH);

    // 公式コードに準拠した初期設定
    start();
    writeByte(0x8f); // ディスプレイON, 明るさ最大
    stop();

    start();
    writeByte(0x40); // 自動インクリメントモード
    stop();

    start();
    writeByte(0xc0); // アドレス0から書き込み
    for (int i = 0; i < 6; i++) {
        writeByte(0xff); // すべてのセグメントとドットを点灯
    }
    stop();
    delay(1000);
    
    start();
    writeByte(0x40); // 自動インクリメントモード
    stop();
    
    start();
    writeByte(0xc0); // アドレス0から書き込み
    for (int i = 0; i < 6; i++) {
        writeByte(0x00); // 全セグメントを消灯
    }
    stop();
    delay(100);
    
    Serial.println("Arduino ready.");
}

void loop() {
    // 公式コードに準拠した通信シーケンス
    start();
    writeByte(0x40);
    stop();

    start();
    writeByte(0xc0);
    
    // 6桁のデータ
    writeByte(0b00000110); // 1
    writeByte(0b01011011); // 2
    writeByte(0b01001111); // 3
    writeByte(0b01100110); // 4
    writeByte(0b00000110); // 1
    writeByte(0b01011011); // 2
    
    stop();
    
    // ディスプレイ制御コマンド
    start();
    writeByte(0x8f);
    stop();
    
    delay(2000);
}
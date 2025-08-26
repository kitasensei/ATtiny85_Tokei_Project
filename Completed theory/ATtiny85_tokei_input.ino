//チャタリング防止回路
//mybotton == 1 で IO D12 ボタン押
//

int myButton = 0;

void setup() {
  pinMode(12, INPUT_PULLUP);//IOの設定 D12を入力、プルアップ
  Serial.begin(112500);//ボーレート設定
}

void loop() {
  int button_input = digitalRead(12);//IO D12 の確認

  if (myButton == 0 && button_input == LOW) {//チャタリング処理、IO D12 入力あり
    myButton = 1;
    Serial.println("ボタンＯＮ");
  }

  if (button_input == HIGH) {//IO D12 入力なし
    if (myButton == 1) {
      myButton = 0;
      Serial.println("ボタンＯＦＦ");  
    }
  }
}
//myButtonが2で入力がON（チャタリング対策済み）
//
//
int myButton = 0;

void setup() {
  pinMode(12, INPUT_PULLUP);
  Serial.begin(112500);
}

void loop() {
  int button_input = digitalRead(12);

  if ((myButton == 0) && button_input == HIGH){ // 入力OFF
      Serial.println("ボタンOFF");
      Serial.print("myButton = ");
      Serial.println(myButton);
    }

  if (myButton == 0 && button_input == LOW) {
    myButton = 1;//チャタリング対策用
    }

  if (mybotton == 1 ++ (button_input == LOW)) {   //入力ON
      myButton = 2;
        Serial.println("ボタンON");
        Serial.print("myButton = ");
        Serial.println(myButton);
  }
}
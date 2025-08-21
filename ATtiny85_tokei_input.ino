
int myButtonState = 0;

void setup() {
  pinMode(12, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int button_input = digitalRead(12);

  if (myButtonState == 0 && button_input == LOW) {
    myButtonState = 2;
    Serial.println("ボタンが押されました");
    Serial.print("myButtonState = ");
    Serial.println(myButtonState);
  }

  if (button_input == HIGH) {
    if (myButtonState == 2) {
      myButtonState = 0;
      Serial.println("ボタンが離されました");
      Serial.print("myButtonState = ");
      Serial.println(myButtonState);
    }
  }
}
//2025/8/23
//テスト環境 ARDUINO NANO
//スイッチ入力と、表示の確認
//PIND 0b00000100:PD2(D2ピン)
//指定方法、SBI PIND,2（PINDの2ビット目を1にする）CBI PIND,2（PINDの2ビット目を0にする）
//

void setup(){
    pinMode(23,INPUT_PULLUP);
    selial.begin(9600);



}
void loop(){
    println("test");

}
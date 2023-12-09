// 블루투스로 값을 받아와서 레이저 출력

#include <SoftwareSerial.h>
#define BTtx 2
#define BTrx 3
#define pin_Laser 13
SoftwareSerial BT(BTtx, BTrx);    // 블루투스

//BT(2,3)
char data = 'F';     // 처음에는 꺼져있음
void setup() {
 BT.begin(9600);      // 블루투스
 Serial.begin(9600);  
 pinMode(pin_Laser, OUTPUT);    // 레이저
}
void loop()
{
    if(BT.available()>0)
    {
        data = BT.read();   // 블루투스 데이터 읽기
     }
    if(data == 'T')     // 받은 데이터가 'T' 레이저 이면 켜짐
    {
       digitalWrite(pin_Laser, HIGH);
      Serial.println("Laser ON"); 
    }
    else if(data == 'F') {  // 받은 데이터가 'F' 이면 레이저 2번 깜빡
      digitalWrite(pin_Laser, HIGH);
      delay(500);
      digitalWrite(pin_Laser, LOW);
      delay(500);
      digitalWrite(pin_Laser, HIGH);
      delay(500);
      digitalWrite(pin_Laser, LOW);
      Serial.println("Laser ..");
 }
    else if(data == 'N') {  // 받은 데이터가 'N' 이면 레이저 꺼짐
      digitalWrite(pin_Laser, LOW);
      Serial.println("Laser OFF");
 }
}

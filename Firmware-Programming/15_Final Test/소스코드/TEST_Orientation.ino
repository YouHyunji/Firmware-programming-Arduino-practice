// 블루투스로 값 읽어오기
// 각도가 20도(x축) 이내이면 레이저 출력

#include <SoftwareSerial.h>
#define BTtx 2
#define BTrx 3
#define pin_Laser 13
SoftwareSerial BT(BTtx, BTrx);    // 블루투스

//BT(2,3)
int data;     // 처음에는 꺼져있음
void setup() {
 BT.begin(9600);      // 블루투스
 Serial.begin(9600);  
 pinMode(pin_Laser, OUTPUT);
}
void loop()
{
    if(BT.available()>0)
    {
        data = BT.read();   // 블루투스 데이터 읽기
     }
    if(data > 20)     // 20도 이내면
    {
       digitalWrite(pin_Laser, HIGH); 
      Serial.println("Laser ON"); 
    }
    else{
      digitalWrite(pin_Laser, LOW);
      Serial.println("Laser OFF");
 }
}

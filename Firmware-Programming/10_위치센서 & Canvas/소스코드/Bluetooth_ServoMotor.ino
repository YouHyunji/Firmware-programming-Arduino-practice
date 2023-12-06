// 블루투스 모듈로 서보모터 출력
#include <SoftwareSerial.h>
#include <Servo.h>

Servo myServo;
#define BT_TX 2
#define BT_RX 3
//#define LED_Red 13
SoftwareSerial BT(BT_TX, BT_RX);    // 블루투스
  
void setup() {
 myServo.attach(9);  // 서보모터
 BT.begin(9600);      // 블루투스
 Serial.begin(9600);  
 // pinMode(LED_Red, OUTPUT);
}
void loop()
{
    if(BT.available()>0)
    {
        int servoPos = BT.read();
        //data = BT.read();   // 블루투스 데이터 읽기
        Serial.println(servoPos);
        myServo.write(servoPos);
    }
    
}

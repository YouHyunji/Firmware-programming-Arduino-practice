// TTS : 서브모터 동작
// 값 입력받아 0,90,180도 출력, 음성도 출력

#include <SoftwareSerial.h>
#include <Servo.h>

#define BTtx 2
#define BTrx 3
Servo myServo;
int pin_Servo = 10;  // 서브모터

SoftwareSerial BT(BTtx, BTrx);    // 블루투스

//BT(2,3)
int data;       // int형
void setup() {
 BT.begin(9600);  //블루투스
 myServo.attach(pin_Servo);
 Serial.begin(9600);  
}
void loop()
{
    if(BT.available()>0)
    {
        data = BT.read();   // 블루투스 데이터 읽기
     }
    if(data == 0)     
    {
      myServo.write(0);
      Serial.println("0"); 
    }
    else if(data == 90) { 
      myServo.write(90);
      Serial.println("90");
    }
    else if(data == 180) { 
      myServo.write(180);
      Serial.println("180");
    }
}

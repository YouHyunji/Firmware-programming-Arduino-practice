// 블루투스 LED 제어
// 버튼 4개로 2개의 LED 제어
#include <SoftwareSerial.h>
#include <Servo.h>
#define BTtx 2
#define BTrx 3
#define LED_Red 13
#define LED_Yellow 12
SoftwareSerial BT(BTtx, BTrx);    // 블루투스

//BT(2,3)
char data;     // 처음에는 꺼져있음
void setup() {
 BT.begin(9600);      // 블루투스
 Serial.begin(9600);  
 pinMode(LED_Red, OUTPUT);
 pinMode(LED_Yellow, OUTPUT);
}
void loop()
{
    if(BT.available()>0)
    {
        data = BT.read();   // 블루투스 데이터 읽기
     

     switch(data) {
      case '1':     // ON/ON 이면
        LED(HIGH,HIGH,"ON","ON");
        break;
        
      case '2':     // ON/OFF 이면
        LED(HIGH,LOW,"ON","OFF");
        break;
         
      case '3':     // OFF/ON 이면
        LED(LOW,HIGH,"OFF","ON");
        break;

      case '4':     // OFF/OFF 이면
        LED(LOW,LOW,"OFF","OFF");
        break;
     }
    }
}
void LED(int LED_Red_Val, int LED_Yellow_Val, String Red_Text, String Yellow_Text) 
{

        digitalWrite(LED_Red, LED_Red_Val);
        digitalWrite(LED_Yellow, LED_Yellow_Val);
        Serial.println("LED_Red " + Red_Text);
        Serial.println("LED_Yellow " + Yellow_Text);
} 


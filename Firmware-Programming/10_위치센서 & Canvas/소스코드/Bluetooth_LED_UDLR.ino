// 블루투스 모듈로 LED 2개 출력하기
#include <SoftwareSerial.h>
#define BTtx 2
#define BTrx 3
#define LED_Red 13
#define LED_Green 12
SoftwareSerial BT(BTtx, BTrx);    // 블루투스

//BT(2,3)
char data = 'F';     // 처음에는 꺼져있음

void setup() {
 BT.begin(9600);      // 블루투스
 Serial.begin(9600);  
 pinMode(LED_Red, OUTPUT);
 pinMode(LED_Green, OUTPUT);
}
void loop()
{
    if(BT.available()>0)
    {
        data = BT.read();   // 블루투스 데이터 읽기
    }
    if(data == 'N')     // 북쪽이면, 둘다 켜지기
    {
      digitalWrite(LED_Red, HIGH);
      digitalWrite(LED_Green, HIGH);
      Serial.println("RED LED ON, Green LED ON"); 
    }
    else if(data == 'E') {  // 동쪽이면, 오른쪽 LED만 켜지기
      digitalWrite(LED_Red, LOW);
      digitalWrite(LED_Green, HIGH);
      Serial.println("RED LED OFF, Green LED ON");
    }
    
    else if(data == 'S') {  // 남쪽이면, 둘다 꺼지기
      digitalWrite(LED_Red, LOW);
      digitalWrite(LED_Green, LOW);
      Serial.println("RED LED OFF, Green LED OFF");
    }
    else if(data == 'W') {  // 서쪽이면, 왼쪽 LED만 켜지기
      digitalWrite(LED_Red, HIGH);
      digitalWrite(LED_Green, LOW);
      Serial.println("RED LED ON, Green LED OFF");
    }
    else {  // 아무것도 아니면 둘다 꺼진 상태
      digitalWrite(LED_Red, LOW);
      digitalWrite(LED_Green, LOW);
      Serial.println("What?");
    }
 
}

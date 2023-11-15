// 음성인식 모듈로 RGB LED 출력하기
#include <SoftwareSerial.h>
#define BTtx 2
#define BTrx 3
#define RED 10
#define GREEN 9
#define BLUE 8
SoftwareSerial BT(BTtx, BTrx);    // 블루투스

//BT(2,3)
char data = 'F';     // 초기값
void setup() {
 BT.begin(9600);      // 블루투스
 Serial.begin(9600);  
 pinMode(RED, OUTPUT);
 pinMode(GREEN, OUTPUT);
 pinMode(BLUE, OUTPUT);
}
void loop()
{
    if(BT.available()>0)
    {
        data = BT.read();   // 블루투스 데이터 읽기
     }
    if(data == 'R')     // 받은 데이터가 'R' 이면 빨간색 켜짐
    {
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, LOW);
      Serial.println("LED RED"); 
    }
    else if(data == 'G') { // 받은 데이터가 'G' 이면 초록색 켜짐
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
      digitalWrite(BLUE, LOW);
      Serial.println("LED GREEN");
    }
    else if(data == 'B') { // 받은 데이터가 'B' 이면 파란색 켜짐
      digitalWrite(BLUE, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, LOW);
      Serial.println("LED BLUE");
    }else {      // 다른 데이터면 전부 끄기
      digitalWrite(BLUE, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, LOW);
      Serial.println("LED LOW");
    }
}

// 블루투스 모듈로 LED 1개 출력하기
#include <SoftwareSerial.h>
#define BTtx 2
#define BTrx 3
#define LED_Red 13
SoftwareSerial BT(BTtx, BTrx);    // 블루투스

//BT(2,3)
char data = 'F';     // 처음에는 꺼져있음
void setup() {
 BT.begin(9600);      // 블루투스
 Serial.begin(9600);  
 pinMode(LED_Red, OUTPUT);
}
void loop()
{
    if(BT.available()>0)
    {
        data = BT.read();   // 블루투스 데이터 읽기
     }
    if(data == 'T')     // 받은 데이터가 'T' 이면 ( = 버튼 ON 클릭하면 )
    {
      digitalWrite(LED_Red, HIGH);
      Serial.println("LED ON"); 
    }
    else if(data == 'F')  // 받은 데이터가 'F' 이면 ( = 버튼 OFF 클릭하면)
      digitalWrite(LED_Red, LOW);
      Serial.println("LED OFF");
    }
}


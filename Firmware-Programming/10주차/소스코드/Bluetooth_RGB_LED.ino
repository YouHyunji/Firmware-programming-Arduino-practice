// 블루투스 입력 받아 RGB LED 출력하기
// 빨강, 초록 고정값 & 파랑 : 블루투스 입력으로 받기
// 블루투스 입력 값에 따라 노랑~흰색으로 바뀐다.

#include <SoftwareSerial.h>

#define BT_Tx 2
#define BT_Rx 3
SoftwareSerial BT(BT_Tx, BT_Rx);    // 블루투스

// RGB LED 
int LED_Red_Pin = 11;   // 아날로그 입력
int LED_Green_Pin = 10;
int LED_Blue_Pin = 9;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);      // 블루투스 ( 주의!!! )
  pinMode(LED_Red_Pin, OUTPUT);
  pinMode(LED_Green_Pin, OUTPUT);
  pinMode(LED_Blue_Pin, OUTPUT);
}

void loop() {
 
    if(BT.available() >0 ) {
      int Blue = BT.read();
      Blue = map(Blue, 0, 180, 0, 255); // Map : 범위 변경 ( 원래 범위, 변경 범위 )
      RGB_Color(255,255,Blue);

    Serial.print("Blue LED = ");
    Serial.println(Blue);  // 파란색 (바뀐 범위)
    
    }
    
}

// 색 섞는 함수

void RGB_Color(int LED_Red_Val, int LED_Green_Val, int LED_Blue_Val) 
{
  analogWrite(LED_Red_Pin, LED_Red_Val);
  analogWrite(LED_Green_Pin, LED_Green_Val);
  analogWrite(LED_Blue_Pin, LED_Blue_Val);
  
} 

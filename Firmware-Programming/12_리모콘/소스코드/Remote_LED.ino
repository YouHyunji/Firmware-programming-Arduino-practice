// 리모콘 LED 출력

#include <IRremote.h>
#define IR_RECEIVE_PIN 8
#define IR_BUTTON_1 69    // 리모콘 1번 버튼 지정
#define IR_BUTTON_2 70    // 리모콘 2번 버튼 지정

#define LED_Blue 12
#define LED_Green 11

byte state_LED_Blue = LOW;
byte state_LED_Green = LOW;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);   //리모콘
  pinMode(LED_Blue, OUTPUT);
  pinMode(LED_Green, OUTPUT);
}

void loop() {
 
    if(IrReceiver.decode()) {
      IrReceiver.resume();
      int command = IrReceiver.decodedIRData.command;   // 데이터 읽기

      switch( command ) {
        case IR_BUTTON_1: {
          state_LED_Blue = (state_LED_Blue == LOW) ? HIGH : LOW;    // 꺼져있으면 HIGH
          digitalWrite(LED_Blue, state_LED_Blue);
          Serial.println("Blue LED");
          break;
        }
        case IR_BUTTON_2: {
          state_LED_Green = (state_LED_Green == LOW) ? HIGH : LOW;
          digitalWrite(LED_Green, state_LED_Green);
          Serial.println("Green LED");
          break;
        }
        default: {
          digitalWrite(LED_Blue, LOW);
          digitalWrite(LED_Green, LOW);
          Serial.println("Try again");
        }
      }
    }
   
}

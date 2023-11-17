// 리모콘 기본 조작
// 버튼 지정

#include <IRremote.h>
#define IR_RECEIVE_PIN 8
#define IR_BUTTON_1 69    // 리모콘 1번 버튼 지정
#define IR_BUTTON_2 70    // 리모콘 2번 버튼 지정
#define IR_BUTTON_3 71    // 리모콘 3번 버튼 지정

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);   //리모콘 
}

void loop() {
 
    if(IrReceiver.decode()) {
      IrReceiver.resume();
      int command = IrReceiver.decodedIRData.command;   // 데이터 읽기

      switch( command ) {
        case IR_BUTTON_1: {
          Serial.println("You are pressed button no.1");
          break;
        }
        case IR_BUTTON_2: {
          Serial.println("You are pressed button no.2");
          break;
        }
        case IR_BUTTON_3: {
          Serial.println("You are pressed button no.3");
          break;
        }
        default: {
          Serial.println("Try again");
        }
      }
    }
   
}

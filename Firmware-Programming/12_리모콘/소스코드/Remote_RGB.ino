// 리모콘 RGB LED 출력

#include <IRremote.h>
#define IR_RECEIVE_PIN 8
#define IR_BUTTON_1 69    // 리모콘 1번 버튼 지정
#define IR_BUTTON_2 70    // 리모콘 2번 버튼 지정
#define IR_BUTTON_3 71    // 리모콘 3번 버튼 지정
#define IR_BUTTON_4 68    // 리모콘 4번 버튼 지정
#define IR_BUTTON_5 64    // 리모콘 5번 버튼 지정
#define IR_BUTTON_6 67    // 리모콘 6번 버튼 지정
#define IR_BUTTON_7 7    // 리모콘 7번 버튼 지정

#define LED_Red 11
#define LED_Green 10
#define LED_Blue 9

//byte state_LED_Blue = LOW;
//byte state_LED_Green = LOW;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);   //리모콘
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Blue, OUTPUT);
  pinMode(LED_Green, OUTPUT);
}

void loop() {
 
    if(IrReceiver.decode()) {
      IrReceiver.resume();
      int command = IrReceiver.decodedIRData.command;   // 데이터 읽기

      switch( command ) {
        case IR_BUTTON_1: {         // 빨간색
          digitalWrite(LED_Red, HIGH);
          Serial.println("Red");
          break;
        }
        case IR_BUTTON_2: {         // 초록색
          digitalWrite(LED_Green, HIGH);
          Serial.println("Green");
          break;
        }
        case IR_BUTTON_3: {       // 파란색
          digitalWrite(LED_Blue, HIGH);
          Serial.println("Blue");
          break;
        }
        case IR_BUTTON_4: {       // 노란색
          digitalWrite(LED_Green, HIGH);
          digitalWrite(LED_Red, HIGH);
          Serial.println("Yellow");
          break;
        }
        case IR_BUTTON_5: {     // 마젠타
          digitalWrite(LED_Red, HIGH);
          digitalWrite(LED_Blue, HIGH);
          Serial.println("Magenta");
          break;
        }
        case IR_BUTTON_6: {     // Cyan
          digitalWrite(LED_Blue, HIGH);
          digitalWrite(LED_Green, HIGH);
          Serial.println("Cyan");
          break;
        }
        case IR_BUTTON_7: {     // White
          digitalWrite(LED_Blue, HIGH);
          digitalWrite(LED_Green, HIGH);
          digitalWrite(LED_Red, HIGH);
          Serial.println("White");
          break;
        }
        default: {
          digitalWrite(LED_Blue, LOW);
          digitalWrite(LED_Green, LOW);
          digitalWrite(LED_Red, LOW);
          Serial.println("Try again");
        }
      }
    }
   
}

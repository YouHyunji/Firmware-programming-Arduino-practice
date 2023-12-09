// 리모콘으로 LED & RGB LED & 레이저 출력

#include <IRremote.h>
#define IR_RECEIVE_PIN 9
#define IR_BUTTON_1 69    // 리모콘 1번 버튼 지정
#define IR_BUTTON_2 70    // 리모콘 2번 버튼 지정
#define IR_BUTTON_3 71    // 리모콘 3번 버튼 지정
#define IR_BUTTON_4 68    // 리모콘 4번 버튼 지정
#define IR_BUTTON_5 64    // 리모콘 5번 버튼 지정
#define IR_BUTTON_6 67    // 리모콘 6번 버튼 지정
#define IR_BUTTON_7 7    // 리모콘 7번 버튼 지정
#define IR_BUTTON_8 21    // 리모콘 8번 버튼 지정
#define IR_BUTTON_9 9    // 리모콘 9번 버튼 지정
#define IR_BUTTON_0 25    // 리모콘 0번 버튼 지정

#define LED_Red 7   // RGB Red
#define LED_Green 6 // RGB Green
#define LED_Blue 5  // RGB Blue
#define LED 11      // 일반 LED

int pin_Laser = 13;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);   //리모콘
  
  pinMode(LED, OUTPUT);
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Blue, OUTPUT);
  pinMode(LED_Green, OUTPUT);
  pinMode(pin_Laser, OUTPUT);
}

void loop() {
 
    if(IrReceiver.decode()) {
      IrReceiver.resume();
      int command = IrReceiver.decodedIRData.command;   // 리모콘 데이터 읽기

      switch( command ) {
        case IR_BUTTON_1: {         // 일반 LED ON
          digitalWrite(LED, HIGH);
          break;
        }
        case IR_BUTTON_2: {         // 일반 LED OFF
          digitalWrite(LED, LOW);
          break;
        }

        
        case IR_BUTTON_3: {       // RGB 파란색 ON
          digitalWrite(LED_Blue, HIGH);
          break;
        }
        case IR_BUTTON_4: {       // RGB 파란색 OFF
          digitalWrite(LED_Blue, LOW);
          break;
        }
        case IR_BUTTON_5: {     // RGB 초록색 켜짐
          digitalWrite(LED_Green, HIGH);
          break;
        }
        case IR_BUTTON_6: {     // RGB 초록색 꺼짐
          digitalWrite(LED_Green, LOW);
          break;
        }
        case IR_BUTTON_7: {     // RGB 빨간색 켜짐
          digitalWrite(LED_Red, HIGH);
          break;
        }
        case IR_BUTTON_8: {     // RGB 빨간색 꺼짐
          digitalWrite(LED_Red, LOW);
          break;
        }
        case IR_BUTTON_9: {     // 레이저 켜짐
          digitalWrite(pin_Laser, HIGH);
          break;
        }
         case IR_BUTTON_0: {     // 레이저 꺼짐
          digitalWrite(pin_Laser, LOW);
          break;
        }
      
      }
    }
   
}

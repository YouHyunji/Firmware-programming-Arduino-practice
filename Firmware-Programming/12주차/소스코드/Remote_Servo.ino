// 리모콘 서보모터 출력

#include <IRremote.h>
#include <Servo.h>

#define IR_RECEIVE_PIN 9
#define IR_BUTTON_Up 24    // 리모콘 위쪽 버튼 지정 24
#define IR_BUTTON_Left 8    // 리모콘 왼쪽 버튼 지정 8 
#define IR_BUTTON_Right 90    // 리모콘 오른쪽 버튼 지정 90
#define IR_BUTTON_Ok 28    // 리모콘 OK 버튼 지정 28

Servo myServo;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);   //리모콘
  myServo.attach(11);  // 서보모터

}

void loop() {
 
    if(IrReceiver.decode()) {
      IrReceiver.resume();
      int command = IrReceiver.decodedIRData.command;   // 데이터 읽기

      switch( command ) {
        
        case IR_BUTTON_Up: {         
          Serial.println("90");
          myServo.write(90);
          break;
        }
        case IR_BUTTON_Ok: {         
          Serial.println("좌우로 흔들기");
          myServo.write(0);
          delay(500);
          myServo.write(180);
          delay(500);
          myServo.write(0);
          delay(500);
          myServo.write(90);
          delay(500);
          break;
        }
        case IR_BUTTON_Left: {       
          Serial.println("0");
          myServo.write(0);
          break;
        }
        case IR_BUTTON_Right: {       
          Serial.println("180");
          myServo.write(180);
          break;
        }
        default: {
          Serial.println("Try again");
        }
      }
    }
   
}

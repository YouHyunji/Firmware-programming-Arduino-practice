// 리모콘 기본 조작

#include <IRremote.h>
#define IR_RECEIVE_PIN 9

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);   //리모콘 
}

void loop() {
 
    if(IrReceiver.decode()) {
      IrReceiver.resume();
      Serial.println(IrReceiver.decodedIRData.command);
    }
}

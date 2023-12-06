// 조이스틱으로 서보모터 출력
// x축으로 좌,우 움직이기 ( 아날로그 출력)
#include <Servo.h>

Servo myServo;
int Analog_X = A0;  // 조이스틱 X축

void setup() {
 Serial.begin(9600);
 pinMode(Analog_X, INPUT);
 myServo.attach(9);   // 서보모터
}
void loop()
{
   int val_X_A0;
   int val_Y_A1;
   int val_Z_13;

   val_X_A0 = analogRead(Analog_X);   // 가변저항 : 아날로그

   val_X_A0 = map(val_X_A0, 0, 1023, 0, 180);   // 범위 변경
   myServo.write(val_X_A0);
   
   Serial.print("X : ");
   Serial.println(val_X_A0);
  
}

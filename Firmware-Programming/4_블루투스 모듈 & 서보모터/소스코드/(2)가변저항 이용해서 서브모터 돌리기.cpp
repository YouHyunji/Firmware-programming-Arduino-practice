// 가변저항 이용해서 서브모터 돌리기

#include <Servo.h>

Servo myservo;			// 서브모터 객체
int pinPoten = A0;	 	//가변저항
int val;

void setup() {
 	myservo.attach(9);	// == pinMode
}
void loop() {
  val = analogRead(pinPoten);	// 가변저항값 읽기
  val = map(val, 0, 1023, 0 ,180);
  myservo.write(val);
  delay(20);
}
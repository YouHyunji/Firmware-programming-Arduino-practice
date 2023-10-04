// 패시브 부저 작동시키기 : 도레미 연주
// 프로그래머가 직접 제어 가능

int pin_Passive = 10;
void setup() {
  pinMode(pin_Passive, OUTPUT);
}
void loop() {
  tone(pin_Passive, 262);	// 직접제어 : 도
  delay(500);
  noTone(pin_Passive);
  delay(500);
  
  tone(pin_Passive, 294);	// 직접제어 : 레
  delay(500);
  noTone(pin_Passive);
  delay(500);
  
  tone(pin_Passive, 330);	// 직접제어 : 미
  delay(500);
  noTone(pin_Passive);
  delay(500);
}
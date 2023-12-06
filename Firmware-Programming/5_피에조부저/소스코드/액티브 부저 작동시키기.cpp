// 진동소리 내기

int pin_Active = 10;
void setup() {
  pinMode(pin_Active, OUTPUT);
}
void loop() {
  tone (pin_Active, HIGH);		// 패시브 부저 사용할 때에는 digitalWrite가 아닌 tone & noTone
  //digitalWrite(pin_Active, HIGH);	// 액티브 부저만 가능
  delay(1000);
  noTone(pin_Active);
  //digitalWrite(pin_Active, LOW);	// 액티브 부저만 가능
  delay(1000);
}
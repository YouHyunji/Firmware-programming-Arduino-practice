// 레이저 발광 모듈

int pin_Laser = 13;

void setup() {
  Serial.begin(9600);
  pinMode(pin_Laser, OUTPUT);
  pinMode(pin_Button, INPUT_PULLUP);    // 스위치
}

void loop() {
    int val = digitalRead(pin_Button);
    Serial.println(val);
    delay(100);

    if(val == LOW) {
      digitalWrite(pin_Laser, HIGH);
    }
    else {
      digitalWrite(pin_Laser, LOW);
    }
}

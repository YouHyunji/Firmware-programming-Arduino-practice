// 레이저 발광 모듈
// 스위치 풀업

int pin_Laser = 13;
int pin_Button = 12;

void setup() {
  Serial.begin(9600);
  pinMode(pin_Laser, OUTPUT);
  pinMode(pin_Button, INPUT_PULLUP);    // 스위치 (풀업) :  저항 VCC 연결
}

void loop() {
    int val = digitalRead(pin_Button);
    Serial.println(val);
    delay(100);

    if(val == LOW) {    
      digitalWrite(pin_Laser, HIGH);  // 0일 때 1
    }
    else {
      digitalWrite(pin_Laser, LOW);
    }
}

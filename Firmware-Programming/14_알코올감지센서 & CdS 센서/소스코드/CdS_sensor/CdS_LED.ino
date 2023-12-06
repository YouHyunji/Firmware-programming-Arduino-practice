// CdS 센서(포토레지스트)
// 일반소자, 측정 모듈
// 200 이상이면 LED 출력

int pin_CdS = A0;   // 일반소자
//int pin_CdS = A5;   // 측정모듈
int pin_LED = 13;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pin_LED,OUTPUT);
  pinMode(pin_CdS,INPUT);   // INPUT
}

void loop() {
    val = analogRead(pin_CdS);
    Serial.println(val);      // 측정결과 출력
    delay(100);
    
    if(val<=200) {    // 어두우면 켜짐
      digitalWrite(pin_LED, HIGH);
    }
    else {            // 밝으면 꺼짐
      digitalWrite(pin_LED, LOW);
    }
}

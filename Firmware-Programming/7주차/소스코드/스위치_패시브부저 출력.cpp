// 스위치로 패시브부저 출력
// 풀다운 저항

int pin_Passive = 10;
int button = 2;

void setup() {
  Serial.begin(9600);
  pinMode(pin_Passive, OUTPUT);
  pinMode(button, INPUT);     // 풀다운
}

void loop() {
  
  int readValue = digitalRead(button);   // 스위치 : 디지털값
  
  if(readValue == HIGH) {        // 버튼이 눌렸을 때 == 1 
   tone(pin_Passive, 262);    // '도' 출력
   Serial.println("Buzzer : ON");
  } 
  else {
     noTone(pin_Passive);
  }
  
}


// 알콜감지 센서
// LED 출력

int pin_MQ3 = A5;   // 아날로그
int pin_Red = 11;

void setup() {
  Serial.begin(9600);
  pinMode(pin_Red,OUTPUT);
  pinMode(pin_MQ3,INPUT);    // INPUT 설정
}

void loop() {
  Serial.println(analogRead(pin_MQ3));  // 측정결과 출력
  int val = analogRead(pin_MQ3);
 
  if(val>=400) {      // 400 이상 : 빨간색
    digitalWrite(pin_Red, HIGH);
  }
  else  {  
    digitalWrite(pin_Red, LOW);
  }

}

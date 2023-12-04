// MQ-3 알콜감지 센서 측정

int pin_MQ3 = A5;   // 아날로그
int pin_Red = 11;
int pin_Green= 9;
int pin_Blue = 10;

void setup() {
  Serial.begin(9600);
  pinMode(pin_Red,OUTPUT);
  pinMode(pin_Green,OUTPUT);
  pinMode(pin_Blue,OUTPUT);
  pinMode(pin_MQ3,INPUT);    // INPUT 설정
}

void loop() {
  int val = analogRead(pin_MQ3);
  Serial.println(analogRead(val));  // 측정결과 출력

}

// 알콜감지 센서
// RGB 출력

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
  Serial.println(analogRead(pin_MQ3));  // 측정결과 출력
  int val = analogRead(pin_MQ3);
 
  if(val>=400) {      // 400 이상 : 빨간색
    analogWrite(pin_Red,255);
    analogWrite(pin_Green,0);
    analogWrite(pin_Blue,0);
    delay(100);
  }
  else if(val>=300 && val<=400)  {  // 200~400 : 초록색
    analogWrite(pin_Red,0);
    analogWrite(pin_Green,255);
    analogWrite(pin_Blue,0);
    delay(100);
  }
  else if(val<300) {    // 200 미만 : 파란색
    analogWrite(pin_Red,0);
    analogWrite(pin_Green,0);
    analogWrite(pin_Blue,255);
    delay(100);
  }
}

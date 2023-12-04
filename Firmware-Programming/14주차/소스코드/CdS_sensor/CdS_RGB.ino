// CdS 센서 (일반소자, 측정 모듈)
// RGB 출력

int pin_CdS = A0;   // 일반소자
//int pin_CdS = A5;   // 측정모듈
int pin_Red = 11;     // RGB : 아날로그
int pin_Blue = 10;
int pin_Green= 9;

void setup() {
  Serial.begin(9600);
  pinMode(pin_Red,OUTPUT);
  pinMode(pin_Green,OUTPUT);
  pinMode(pin_Blue,OUTPUT);
  pinMode(pin_CdS,INPUT);    // INPUT 설정
}

void loop() {
  Serial.println(analogRead(pin_CdS));  // 측정결과 출력
  int val = analogRead(pin_CdS);
  
  if(val >=400) {      // 400 이상 : 빨간색
    analogWrite(pin_Red,255);
    analogWrite(pin_Green,0);
    analogWrite(pin_Blue,0);
    delay(100);
  }
  else if(val >=200 && val <=400)  {  // 200~400 : 초록색
    analogWrite(pin_Red,0);
    analogWrite(pin_Green,255);
    analogWrite(pin_Blue,0);
    delay(100);
  }
  else if(val<200) {    // 200 미만 : 파란색
    analogWrite(pin_Red,0);
    analogWrite(pin_Green,0);
    analogWrite(pin_Blue,255);
    delay(100);
  }
}

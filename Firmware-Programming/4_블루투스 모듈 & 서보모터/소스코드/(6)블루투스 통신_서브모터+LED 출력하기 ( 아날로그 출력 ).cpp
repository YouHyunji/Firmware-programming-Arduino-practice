// (아날로그출력) 블루투스 통신 : 모터+LED

#include<SoftwareSerial.h>
#include<Servo.h>

Servo myServo;
#define BTtx 2
#define BTrx 3
#define LED_Red 11    // 아날로그 출력
SoftwareSerial BT(BTtx, BTrx); 
int angle=0;
int OutValue_LED = 0;   // LED 아날로그 출력을 위한 변수

void setup(){
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(LED_Red, OUTPUT);
  myServo.attach(9);
}

void loop(){
  if(BT.available()>0){
    angle = BT.read();
    Serial.println(angle);
    myServo.write(angle);
  }
  
    OutValue_LED = map(angle, 0, 180, 0, 255);	 // 범위 변겅
    analogWrite(LED_Red, angle);
    
}
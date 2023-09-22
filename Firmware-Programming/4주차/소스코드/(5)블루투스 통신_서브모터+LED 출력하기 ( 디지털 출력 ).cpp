// 블루투스 통신_모터+LED ( 디지털 출력 )

#include<SoftwareSerial.h>
#include<Servo.h>

Servo myServo;
#define BTtx 2		// Tx
#define BTrx 3		// Rx
#define LED_Red 13
SoftwareSerial BT(BTtx, BTrx); 
int angle=0;		// 서브모터 각도

void setup(){
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(LED_Red, OUTPUT);
  myServo.attach(9);		// == pinMode
}

void loop(){
  if(BT.available()>0){
    angle = BT.read();		// 블루투스 각도값 읽어오기
    Serial.println(angle);
    myServo.write(angle);	// 읽어온 값 출력하기
  }

  if(angle>90){		// 90도 이상이면 켜지기
    digitalWrite(LED_Red, HIGH);	
  }
 else{
    digitalWrite(LED_Red, LOW);
  }
}
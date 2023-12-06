// 초음파센서 : 거리 측정 후 LED 점멸하기
#define pin_Echo 11
#define pin_Trig 12
#define LED_Red 4
long duration;        // int로 하면 불안정한 값이 나옴.
int distance;
void setup(){
  pinMode(pin_Trig, OUTPUT);    // 초음파 나감
  pinMode(pin_Echo, INPUT);     // 초음파가 들어옴
  pinMode(LED_Red, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor Test!");
}

void loop(){
  digitalWrite(pin_Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_Trig, LOW);
  
  duration = pulseIn(pin_Echo, HIGH);   // 초음파가 들어온 시간 측정
  distance = duration * 340 * 100 / 1000000 /2;   // 거리 측정
  
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println("cm");

  if(distance < 40){    // 가까워지면 LED 켜지기
    digitalWrite(LED_Red, HIGH);
    Serial.println("OK!");
  }else{
    digitalWrite(LED_Red, LOW);
    Serial.println("What?");
  }
}
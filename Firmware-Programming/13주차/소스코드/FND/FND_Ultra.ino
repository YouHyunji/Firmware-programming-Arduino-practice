// 초음파 센서로 거리 측정하기

#define pin_Echo 11
#define pin_Trig 12
long duration;        // int로 하면 불안정한 값이 나옴.
int distance;

#define pin_A 2
#define pin_B 3
#define pin_C 4
#define pin_D 5
#define pin_E 6
#define pin_F 7
#define pin_G 8
#define pin_DP 9

void setup(){
  pinMode(pin_Trig, OUTPUT);    // 초음파 나감
  pinMode(pin_Echo, INPUT);     // 초음파가 들어옴
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor Test!");

 
  pinMode(pin_A, OUTPUT);
  pinMode(pin_B, OUTPUT);
  pinMode(pin_C, OUTPUT);
  pinMode(pin_D, OUTPUT);
  pinMode(pin_E, OUTPUT);
  pinMode(pin_F, OUTPUT);
  pinMode(pin_G, OUTPUT);
  pinMode(pin_DP, OUTPUT);
}

void loop(){
  digitalWrite(pin_Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_Trig, LOW);

  duration = pulseIn(pin_Echo, HIGH);  // 초음파가 들어온 시간 측정
  distance = duration * 340 * 100 / 1000000 /2;   // 거리 = 시간*속도 ( 편도*1, 왕복2 )
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println("cm");

  if(distance >= 0 && distance <= 20){    // 0~20
    FND(1,1,1,1,1,1,0,1);     // 0
    Serial.println("0");
  }
  else if(distance >= 21 && distance <= 40){   // 21~40
    FND(0,1,1,0,0,0,0,1);  // 1
    Serial.println("1");
  }
  else if(distance >= 41){    // 41 이상
    FND(1,1,0,1,1,0,1,1);  // 2
    Serial.println("2");
  }

  
}

void FND(int A, int B, int C,int D, int E, int F, int G, int DP) {
      digitalWrite(pin_A, A);
      digitalWrite(pin_B, B);
      digitalWrite(pin_C, C);
      digitalWrite(pin_D, D);
      digitalWrite(pin_E, E);
      digitalWrite(pin_F, F);
      digitalWrite(pin_G, G);
      digitalWrite(pin_DP, DP);
}

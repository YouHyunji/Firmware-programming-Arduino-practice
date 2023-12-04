// 알콜감지 센서
// FND 출력 

#define pin_A 2
#define pin_B 3
#define pin_C 4
#define pin_D 5
#define pin_E 6
#define pin_F 7
#define pin_G 8
#define pin_DP 9

int pin_MQ3 = A5;   // MQ-3 알콜감지센서

void setup() {
  Serial.begin(9600);
  pinMode(pin_A, OUTPUT);
  pinMode(pin_B, OUTPUT);
  pinMode(pin_C, OUTPUT);
  pinMode(pin_D, OUTPUT);
  pinMode(pin_E, OUTPUT);
  pinMode(pin_F, OUTPUT);
  pinMode(pin_G, OUTPUT);
  pinMode(pin_DP, OUTPUT);
  pinMode(pin_MQ3,INPUT);    // INPUT 설정
}

void loop() {
  Serial.println(analogRead(pin_MQ3));  // 측정결과 출력
  int val = analogRead(pin_MQ3);
  
  if(val>=501) {      // 301 이상 : 3 출력
    FND(1,1,1,1,0,0,1,1);  // 3
  }
  else if(val>=401 && val<=500)  {  // 201~300 : 2 출력
    FND(1,1,0,1,1,0,1,1);  // 2
  }
  else if(val>=301 && val<=400)  {  // 201~300 : 1 출력
    FND(0,1,1,0,0,0,0,1);  // 1
  }
  else if(val>=200 && val<=300) {    // 0~100 : 0 출력
    FND(1,1,1,1,1,1,0,1);  // 0
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

// 조이스틱으로 FND 출력
// 상하좌우 FND 출력
// 스위치는 사용 X

int pinHorizon = A0;    // 조이스틱 Y축
int pinVertical = A1;   // 조이스틱 X축

#define pin_A 2
#define pin_B 3
#define pin_C 4
#define pin_D 5
#define pin_E 6
#define pin_F 7
#define pin_G 8
#define pin_DP 9

void setup() {
  Serial.begin(9600);
 pinMode(pinHorizon, INPUT);    // 조이스틱 X축
 pinMode(pinVertical, INPUT);   // 조이스틱 Y축
 
 //pinMode(pinButton, INPUT_PULLUP);     // 조이스틱 스위치 ( 풀업 )
 //digitalWrite(pinButton, HIGH);
 
 pinMode(pin_A, OUTPUT);
  pinMode(pin_B, OUTPUT);
  pinMode(pin_C, OUTPUT);
  pinMode(pin_D, OUTPUT);
  pinMode(pin_E, OUTPUT);
  pinMode(pin_F, OUTPUT);
  pinMode(pin_G, OUTPUT);
  pinMode(pin_DP, OUTPUT);
}

void loop()
{
   int X_Horizon = analogRead(pinHorizon);
   int Y_Vertical = analogRead(pinVertical);

   // 위쪽 : FND 1 출력
   else if (X_Horizon >= 450 && Y_Vertical >= 1000) {
    FND(0,1,1,0,0,0,0,1);  // 1
    Serial.println("Up(1)");
   }

   // 아래쪽 : FND 2 출력
   if(X_Horizon >=0 && Y_Vertical <= 10) {
    FND(1,1,0,1,1,0,1,1);  // 2
    Serial.println("Down(2)");
   }

   // 왼쪽 : FND 3 출력
   else if (X_Horizon <= 10 && Y_Vertical >= 400) {
    FND(1,1,1,1,0,0,1,1);  // 3
    
    Serial.println("Left(3)");
   }
  
  // 오른쪽 : FND 4 출력
   else if (X_Horizon >= 1000 && Y_Vertical >= 450) {
    FND(0,1,1,0,0,1,1,1);   // 4
    Serial.println("Right(4)");
   }
   
  // 중간일 때 ( 움직이지 않을 때 ) : FND 0 출력
   else {
    FND(1,1,1,1,1,1,0,1);  // 0
    Serial.println("Center(0)");
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

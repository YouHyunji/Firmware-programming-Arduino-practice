// FND 스위치 (3개)
// 3,6,9 출력

int Button_3 = 10;
int Button_6 = 11;
int Button_9 = 12;

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
  pinMode(pin_A, OUTPUT);
  pinMode(pin_B, OUTPUT);
  pinMode(pin_C, OUTPUT);
  pinMode(pin_D, OUTPUT);
  pinMode(pin_E, OUTPUT);
  pinMode(pin_F, OUTPUT);
  pinMode(pin_G, OUTPUT);
  pinMode(pin_DP, OUTPUT);
  
  pinMode(Button_3, INPUT_PULLUP);
  pinMode(Button_6, INPUT_PULLUP);
  pinMode(Button_9, INPUT_PULLUP);
}
void loop() {
  int val_3 = digitalRead(Button_3);
  int val_6 = digitalRead(Button_6);
  int val_9 = digitalRead(Button_9);

  if(val_3 == LOW) {    
      FND(1,1,1,1,0,0,1,1);  // 3
  }
  else if (val_6 == LOW) {
      FND(1,0,1,1,1,1,1,1);   // 6
  }
  else if (val_9 == LOW) {
      FND(1,1,1,1,0,1,1,1);    // 9
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

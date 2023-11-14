// 조이스틱으로 상하좌우, 스위치 LED 출력

int pinHorizon = A0;    // 조이스틱 Y축
int pinVertical = A1;   // 조이스틱 X축
int pinButton = 2;  // 조이스틱 스위치
int stateButton1 = 0;
int stateButton2 = 0;
int pinLED_Button = 11; // 투명 LED
int pinLED_Right = 7;  // 초록색
int pinLED_UP = 8;    // 빨간색
int pinLED_Down = 9;  // 노란색 

int pinLED_Left = 10; // 파란색


void setup() {
  Serial.begin(9600);
 pinMode(pinHorizon, INPUT);    // 조이스틱 X축
 pinMode(pinVertical, INPUT);   // 조이스틱 Y축
 //pinMode(Digital_Z, INPUT_PULLUP);

 pinMode(pinLED_Button, OUTPUT);
 pinMode(pinButton, INPUT_PULLUP);     // 조이스틱 스위치
 digitalWrite(pinButton, HIGH); 
 pinMode(pinLED_UP, OUTPUT);
 pinMode(pinLED_Down, OUTPUT);
 pinMode(pinLED_Left, OUTPUT);
 pinMode(pinLED_Right, OUTPUT);
}
void loop()
{
   int X_Horizon = analogRead(pinHorizon);
   int Y_Vertical = analogRead(pinVertical);
   Serial.print(X_Horizon);
   Serial.print("\t");
   Serial.println(Y_Vertical);

   stateButton1 = digitalRead(pinButton);    // 조이스틱 스위치
   Serial.println(stateButton1);

   // 아래쪽 : 노란색 LED
   if(X_Horizon >=0 && Y_Vertical <= 10) {
    digitalWrite(pinLED_Down, HIGH);    // ON
   }
   else {
    digitalWrite(pinLED_Down, LOW);
   }

  // 위쪽 : 빨간색 LED 
   if(X_Horizon >= 450 && Y_Vertical >= 1000) {
    digitalWrite(pinLED_UP, HIGH);    //  ON
   }
   else {
    digitalWrite(pinLED_UP, LOW);
   }

   // 왼쪽 : 파란색 LED
   if(X_Horizon <= 10 && Y_Vertical >= 400) {
    digitalWrite(pinLED_Left, HIGH);    // ON
   }
   else {
    digitalWrite(pinLED_Left, LOW);
   }

  // 오른쪽 : 초록색 LED
   if(X_Horizon >= 1000 && Y_Vertical >= 450) {
    digitalWrite(pinLED_Right, HIGH);     
    digitalWrite(pinLED_UP, LOW);   
   }
   else {
    digitalWrite(pinLED_Right, LOW);
   }

  if(stateButton1 == LOW) {   // 0일때
    Serial.println("Switch = HIGH");
    digitalWrite(pinLED_Button, HIGH);    // 스위치 클릭 LED 켜짐 (흰색)
  }
  else {
    digitalWrite(pinLED_Button, LOW);
  }

  stateButton2 = digitalRead(pinButton);  // 보기편하게 하기 위함..
  Serial.println(stateButton2);
  delay(50);
   
}

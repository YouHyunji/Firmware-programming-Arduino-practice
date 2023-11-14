// 조이스틱으로 RGB LED 출력
//상하좌우, 스위치 LED 출력

int pinHorizon = A0;    // 조이스틱 Y축
int pinVertical = A1;   // 조이스틱 X축
int pinButton = 2;  // 조이스틱 스위치
int stateButton1 = 0;

int LED_Red = 11;
int LED_Green = 10;
int LED_Blue = 9;



void setup() {
  Serial.begin(9600);
 pinMode(pinHorizon, INPUT);    // 조이스틱 X축
 pinMode(pinVertical, INPUT);   // 조이스틱 Y축
 
 pinMode(pinButton, INPUT_PULLUP);     // 조이스틱 스위치 ( 풀업 )
 digitalWrite(pinButton, HIGH);
 
 pinMode(LED_Red, OUTPUT);
 pinMode(LED_Green, OUTPUT);
 pinMode(LED_Blue, OUTPUT);
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

   // 아래쪽 : 파랑색
   if(X_Horizon >=0 && Y_Vertical <= 10) {
    RGB_Color(0,0,255);
   }

  // 위쪽 : 빨간색 
   else if (X_Horizon >= 450 && Y_Vertical >= 1000) {
    RGB_Color(255,0,0);
   }

   // 왼쪽 : 초록색
   else if (X_Horizon <= 10 && Y_Vertical >= 400) {
    RGB_Color(0,255,0);
   }
  
  // 오른쪽 : 노란색
   else if (X_Horizon >= 1000 && Y_Vertical >= 450) {
    RGB_Color(255,255,0);  
   }
  // 중간일 때 ( 움직이지 않을 때 )
   else {
    RGB_Color(0,0,0);
   }

 // 스위치
  if(stateButton1 == LOW) {   // 0일때 ( 클릭했을 때 )
    Serial.println("Switch = HIGH");
    RGB_Color(255,255,255);    // 스위치 클릭 LED 켜짐 (흰색)
  }
  delay(50);
  
}


void RGB_Color(int LED_Red_Val, int LED_Green_Val, int LED_Blue_Val) 
{
  analogWrite(LED_Red, LED_Red_Val);
  analogWrite(LED_Green, LED_Green_Val);
  analogWrite(LED_Blue, LED_Blue_Val);
  
} 

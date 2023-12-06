// 스위치로 RGB LED 출력하기
// 스위치 : 풀업 저항

int LED_Red = 11;
int LED_Blue = 10;
int LED_Green = 9;

int button_Red = 4;
int button_Blue = 3;
int button_Green = 2;

void setup() {
  Serial.begin(9600);
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Blue, OUTPUT);
  pinMode(LED_Green, OUTPUT);
  
  pinMode(button_Red, INPUT_PULLUP);     // 풀업
  pinMode(button_Blue, INPUT_PULLUP);     // 풀업
  pinMode(button_Green, INPUT_PULLUP);     // 풀업
}

void loop() {
  
  // * 풀업상태 : 스위치 열려있어야 켜짐
  // 빨간색 LED 제어
  if (digitalRead(button_Red) == LOW) {		
    
    digitalWrite(LED_Red, HIGH); // LED 켜기
    Serial.println("Red LED is ON");  // 시리얼 모니터에 상태 출력
    
  } else {
    digitalWrite(LED_Red, LOW); // LED 끄기
  }

  // 파란색 LED 제어
  if (digitalRead(button_Blue) == LOW) {
    
    digitalWrite(LED_Blue, HIGH);
    Serial.println("Blue LED is ON");  
  } else {
    digitalWrite(LED_Blue, LOW); 
  }

  // 초록색 LED 제어
  if (digitalRead(button_Green) == LOW) {
    digitalWrite(LED_Green, HIGH); 
    Serial.println("Green LED is ON");  
  } else {
    digitalWrite(LED_Green, LOW); 
  }
}


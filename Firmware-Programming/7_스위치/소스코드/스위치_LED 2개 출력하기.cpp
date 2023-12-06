// 스위치 : LED 2개 출력하기
// 풀다운 저항
// 각 스위치 누르면 해당하는 LED가 켜지도록 하기

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
  
  int readValue_Red = digitalRead(button_Red);   // 스위치 : 디지털값
  int readValue_Green = digitalRead(button_Green);
  int readValue_Blue = digitalRead(button_Blue);
  
  // 빨간색 LED
  if(readValue_Red == HIGH) {        // 버튼이 눌렸을 때 == 0 
    digitalWrite(LED_Red, LOW);    // LED 꺼진 상태
  } 
  else {
    digitalWrite(LED_Red, HIGH);
     Serial.println("Red Button : ON");
  }
  
  // 초록색 LED
  if(readValue_Green == HIGH) {        // 버튼이 눌렸을 때 == 0
    digitalWrite(LED_Green, LOW);   
  } 
  else {
    digitalWrite(LED_Green, HIGH);
    Serial.println("Green Button : ON");
  }
  
   // 파란색 LED
  if(readValue_Blue == HIGH) {        // 버튼이 눌렸을 때 == 0
    digitalWrite(LED_Blue, LOW);   
    
  } 
  else {
    digitalWrite(LED_Blue, HIGH);
    Serial.println("Blue Button : ON");
  }
  
}

 

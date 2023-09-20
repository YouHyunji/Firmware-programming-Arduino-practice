// 시리얼 입력 받아 LED 출력하기
// R : 빨강 G : 초록 Y: 노랑

int LED_Red_Pin = 11;
int LED_Green_Pin = 9;
int LED_Blue_Pin = 10;

void setup() {
  	Serial.begin(9600);
	pinMode(LED_Red_Pin, OUTPUT);
	pinMode(LED_Green_Pin, OUTPUT);
	pinMode(LED_Blue_Pin, OUTPUT);
}

void loop() {
 
	if (Serial.available() > 0) {
      
    char color = Serial.read();		// char 변수로 받는다.
      
    switch (color) {
      case 'R':
        RGB_Color(255, 0, 0); // 빨간색
        break;
      case 'G':
        RGB_Color(0, 255, 0); // 초록색
        break;
      case 'Y':
        RGB_Color(255, 255, 0); // 노란색
        break;
      default:
        RGB_Color(0, 0, 0); // 아무 색도 아닌 경우 모든 LED를 끈다.
        break;
    }
    delay(1000);
  }
    
}

// 색 섞는 함수

void RGB_Color(int LED_Red_Val, int LED_Green_Val, int LED_Blue_Val) 
{
	analogWrite(LED_Red_Pin, LED_Red_Val);
	analogWrite(LED_Green_Pin, LED_Green_Val);
 	analogWrite(LED_Blue_Pin, LED_Blue_Val);
}	
// 가변저항 입력 받아 LED 출력하기
// R : 빨강 G : 초록 B : 파랑 -> 가변저항
// 가변저항을 돌리면 노란색~흰색빛으로 바뀐다.

int LED_Red_Pin = 11;
int LED_Green_Pin = 9;
int LED_Blue_Pin = 10;
int pin_Poten = A0;		// 가변저항

void setup() {
  	Serial.begin(9600);
	pinMode(LED_Red_Pin, OUTPUT);
	pinMode(LED_Green_Pin, OUTPUT);
	pinMode(LED_Blue_Pin, OUTPUT);
  	pinMode(pin_Poten, INPUT);
}

int readValue_Blue = 0;	// 가변저항 Input
int OutValue_Blue= 0; 	// 가변저항 출력 ( 파란색 LED )

void loop() {
 
      
    // 파란색 : 가변 저항값 받기
    readValue_Blue = analogRead(pin_Poten);	// 가변 저항값 읽어오기
    OutValue_Blue = map(readValue_Blue, 0, 1023, 0, 255);	// Map : 범위 변경
  	RGB_Color(255,255, OutValue_Blue);	// 색 섞기
  
  	Serial.print("Potentionmeter Value = ");
  	Serial.print(readValue_Blue);	// 원래 입력값

  	Serial.print(", LED's Bright = ");
  	Serial.println(OutValue_Blue);	// 바뀐 입력값
    
}

// 색 섞는 함수

void RGB_Color(int LED_Red_Val, int LED_Green_Val, int LED_Blue_Val) 
{
	analogWrite(LED_Red_Pin, LED_Red_Val);
	analogWrite(LED_Green_Pin, LED_Green_Val);
 	analogWrite(LED_Blue_Pin, LED_Blue_Val);
  
}	
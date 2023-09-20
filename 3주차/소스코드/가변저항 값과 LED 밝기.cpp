// 가변저항 값과 LED 밝기
// 시리얼 모니터에 출력

int LED_Green = 9;		// 아날로그 출력(~)
int Pot_Green = A1;		// 아날로그 입력
int val_Sensor_Green = 0;	// LED 읽어오려는 값
int val_Output_Green = 0;	// LED 출력값

void setup() {
  pinMode(LED_Green, OUTPUT);
  pinMode(Pot_Green, INPUT);
  Serial.begin(9600);
}

void loop() {
  val_Sensor_Green = analogRead(Pot_Green);	// 가변 저항에서 읽어오기

  // map : 범위 바꾸는 메서드 ( 0~1023 : 오리지날 범위 / 0~255 : 바꾸려는 범위 )
  val_Output_Green = map(val_Sensor_Green, 0, 1023, 0, 255);

  Serial.print("Potentionmeter Value = ");
  Serial.print(val_Sensor_Green);	// 원래 입력값

  Serial.print(", LED's Bright = ");
  Serial.println(val_Output_Green);	// 바뀐 입력값

  analogWrite(LED_Green, val_Output_Green);
  delay(10);
}
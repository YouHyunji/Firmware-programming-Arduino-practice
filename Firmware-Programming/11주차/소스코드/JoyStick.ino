// 조이스틱 동작

int Analog_X = A0;  // 조이스틱 X축
int Analog_Y = A1;  // 조이스틱 Y축
int Digital_Z = 3;  // 스위치
  
void setup() {
 Serial.begin(9600);
 pinMode(Analog_X, INPUT);
 pinMode(Analog_Y, INPUT);
 pinMode(Digital_Z, INPUT_PULLUP);
 //pinMode(LED_Red, OUTPUT);
}
void loop()
{
   int val_X_A0;
   int val_Y_A1;
   int val_Z_13;
   val_X_A0 = analogRead(Analog_X);   // 가변저항 : 아날로그
   val_Y_A1 = analogRead(Analog_Y);   // 가변저항 : 아날로그
   val_Z_13 = digitalRead(Digital_Z);   // 스위치 : 디지털
   
   Serial.print("X : ");
   Serial.print(val_X_A0);
   Serial.print(", Y : ");
   Serial.print(val_Y_A1); 
   Serial.print(", Z : ");
   Serial.println(val_Z_13); 
   delay(200);
   
}

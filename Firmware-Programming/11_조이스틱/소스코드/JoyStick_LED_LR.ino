// 조이스틱으로 LED 출력
// x축으로 좌,우 움직일 때 켜지기

int Analog_X = A0;  // 조이스틱 X축
int Analog_Y = A1;  // 조이스틱 Y축
int Digital_Z = 3;  // 스위치
int LED_Red = 13;
int LED_Green = 12;
  
void setup() {
 Serial.begin(9600);
 pinMode(Analog_X, INPUT);
 pinMode(Analog_Y, INPUT);
 pinMode(Digital_Z, INPUT_PULLUP);
 pinMode(LED_Red, OUTPUT);
 pinMode(LED_Green, OUTPUT);
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

   if(val_X_A0 < 1024 && val_X_A0 >= 0) {
    if(val_X_A0 >= 824){        // 조이스틱을 오른쪽으로 꺾었을 때 초록색 ON
      digitalWrite(LED_Red, LOW);
      digitalWrite(LED_Green, HIGH);
    }
    else if(val_X_A0 <= 200){   // 조이스틱을 왼쪽으로 꺾었을 때 빨간색 ON
      digitalWrite(LED_Red, HIGH);
      digitalWrite(LED_Green, LOW);
    }
    else {                    // 아무것도 안하면 다 꺼지기
      digitalWrite(LED_Red, LOW);
      digitalWrite(LED_Green, LOW);
    }
   }
   else {    // -1 예외처리
      digitalWrite(LED_Red, LOW);
      digitalWrite(LED_Green, LOW);
    }
   
}

// 시리얼 통신 읽어오기
// 시리얼 모니터에 입력한 값을 읽어온다.
// LED_Serial

// C++ code

int LED = 13;

void setup() {
   Serial.begin(9600);
   pinMode(LED, OUTPUT);
}

int serialData;

void loop() {
   if (Serial.available() > 0) {
   serialData = Serial.read();		// 시리얼 통신 읽기
   Serial.println(serialData);	
	
   if (serialData == '1'){	// 시리얼 모니터에입력한 값이 1이면
   digitalWrite(LED, HIGH);	// LED (13번) 켜짐
   }
else if (serialData == '0'){	// 시리얼 모니터에 입력한 값이 0이면 
   digitalWrite(LED, LOW);	// LED 꺼짐
      }
   }
}
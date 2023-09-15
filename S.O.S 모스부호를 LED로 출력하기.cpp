// S.O.S 모스부호를 LED에 출력하기

int pin_LED = 13;
int WaitTime = 700;	// 신호를 구분하기 위해 대기하는 시간

void setup() 
{ 
     pinMode(pin_LED, OUTPUT);  	// 13번 : 출력
     Serial.begin(9600);  
} 
void loop() 
{
  // S 출력 ( 3번 짧게 깜빡임 )
   digitalWrite(pin_LED, HIGH);  	// 전압 올리기 (불 켜기)
   delay(100); 				// 0.1초 동안 유지
   digitalWrite(pin_LED, LOW); 		// 전압 내리기 (불 끄기)
   delay(400);				// 0.4초 동안 유지

   digitalWrite(pin_LED, HIGH); 
   delay(100);
   digitalWrite(pin_LED, LOW); 
   delay(400);

   digitalWrite(pin_LED, HIGH); 
   delay(100);
   digitalWrite(pin_LED, LOW); 
   delay(WaitTime);			// 신호 구분
  
  // O ( 3번 길게 깜빡임 )
   digitalWrite(pin_LED, HIGH);  
   delay(400);  
   digitalWrite(pin_LED, LOW); 
   delay(400); 

   digitalWrite(pin_LED, HIGH); 
   delay(400); 
   digitalWrite(pin_LED, LOW); 
   delay(400); 

   digitalWrite(pin_LED, HIGH); 
   delay(400); 
   digitalWrite(pin_LED, LOW); 
   delay(WaitTime);			// 신호 구분
  
  // S 출력 ( 3번 짧게 깜빡임 )
   digitalWrite(pin_LED, HIGH);  	// 전압 올리기 (불 켜기)
   delay(100); 				// 0.1초 동안 유지
   digitalWrite(pin_LED, LOW); 		// 전압 내리기 (불 끄기)
   delay(400);				// 0.4초 동안 유지

   digitalWrite(pin_LED, HIGH); 
   delay(100);
   digitalWrite(pin_LED, LOW); 
   delay(400);

   digitalWrite(pin_LED, HIGH); 
   delay(100);
   digitalWrite(pin_LED, LOW); 
   
   delay(5000);		
}
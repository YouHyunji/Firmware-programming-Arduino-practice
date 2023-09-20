// LED 아날로그 출력하기
// 빨간색 LED : 밝아졌다가 다시 어두워짐
// 초록색 LEd : 어두워졌다가 다시 밝아짐

#define LED_Red 11
#define LED_Green 10

void setup(){
 Serial.begin(9600);
 pinMode(LED_Red, OUTPUT);
 pinMode(LED_Green, OUTPUT);
}

void loop(){
 int valBright;    // 밝기 값
  
 for(valBright=0; valBright<=255; valBright++){
  
 analogWrite(LED_Red, valBright);	// 어두움 -> 밝음
 
 analogWrite(LED_Green, 255-valBright);		// 밝음 -> 어두움
             
 Serial.print("Red : ");
 Serial.print(valBright);
 Serial.print(", Green : ");
 Serial.println(255-valBright);
 
   if(valBright == 255 ) {
     break;  			// 255가 되면 빠져나오고 다음 루프 진행
   }
 }

 delay(100);
 Serial.println("Change");
 
 for(valBright=0; valBright<=255; valBright++){
   
 analogWrite(LED_Red, 255-valBright);	// 밝음 -> 어두움
 analogWrite(LED_Green, valBright);	// 어두움 -> 밝음
 
 Serial.print("Red : "); 
 Serial.print(255-valBright);
 Serial.print(" Green : ");            
 Serial.println(valBright);
             
 }
 
}
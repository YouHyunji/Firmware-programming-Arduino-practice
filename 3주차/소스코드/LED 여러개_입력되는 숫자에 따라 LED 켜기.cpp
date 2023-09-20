// 입력되는 숫자에 따라 LED 켜기
// C++ code
int LED1 = 2;   // 파란색
int LED2 = 4;   // 초록색
int LED3 = 6;   // 빨간색

void setup(){
  Serial.begin(9600);
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

int serialData;

void loop(){
 if (Serial.available() > 0) {
  serialData = Serial.read();    // 시리얼 통신 읽기
   Serial.println(serialData);  

   if(serialData == '1') {	// 1이면 파란색 On
    digitalWrite(LED1, HIGH);
    delay(1000);
   };
   if(serialData == '2') {	// 2이면 초록색 On
    digitalWrite(LED2, HIGH);
    delay(1000);
   };
   if(serialData == '3') {	// 3이면 빨간색 On
    digitalWrite(LED1, HIGH);
    delay(1000);
   };
   if(serialData == '4') {	// 4이면 파/초
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    delay(1000);
   };
   if(serialData == '5') {	// 5이면 파/빨
    digitalWrite(LED1, HIGH);
    digitalWrite(LED3, HIGH);
    delay(1000);
   };
   if(serialData == '6') {	// 6이면 초/빨
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    delay(1000);
   };
   if(serialData == '7') {	// 3개 다 켜짐
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    delay(1000);
   };
  
  digitalWrite(LED1, LOW); 
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
 }
}
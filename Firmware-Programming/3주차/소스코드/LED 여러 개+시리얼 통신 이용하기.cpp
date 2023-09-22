// LED 여러 개 + 시리얼 통신 이용하기

// C++ code
int LED1 = 2;   // 파란색
int LED2 = 4;   // 초록색
int LED3 = 6;   // 파란색

void setup(){
  Serial.begin(9600);
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}
void loop(){
  digitalWrite(LED1, HIGH); 
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  Serial.println("All On");
  delay(1000);
  
  digitalWrite(LED1, LOW); 
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  Serial.println("All Off");
  delay(1000);
}
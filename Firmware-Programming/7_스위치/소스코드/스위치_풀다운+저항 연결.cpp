// 스위치 : 풀다운 저항
// * 플로팅 : 스위치가 열려있을 때, 어떠한 상태도 아닌 상태
// * 풀 다운 (Pull-Down) : 플로팅일 때 값을 끌어내린다.
// == 열려있는 상태를 0로 만든다. ( 일반적인 스위치기능 )
// ** GND에 저항 달아주기
// On (1,HIGH) / Off (0,LOW)

int LED_Red = 13;
int button_Push = 8;

void setup() {
  Serial.begin(9600);
  pinMode(LED_Red, OUTPUT);
  pinMode(button_Push, INPUT);     // *** 풀 다운 : INPUT
}

void loop() {
  int readValue = digitalRead(button_Push);   // 스위치 : 디지털값
  Serial.println(readValue);
  
  //  스위치가 닫혀있는 상태 : 누른 상태 == 1
  if(readValue == HIGH) {         
    digitalWrite(LED_Red, HIGH);    // LED 켜지기
  } 
   
  // 스위치가 열려있는 상태 : 누르지 않은 상태 == 0
  else {                         
    digitalWrite(LED_Red, LOW);
  }

}

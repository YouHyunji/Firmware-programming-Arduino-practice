// 스위치 : 풀업 저항
// * 플로팅 : 스위치가 열려있을 때, 어떠한 상태도 아닌 상태
// * 풀업 (Pull-Up) : 플로팅일 때 값을 끌어올린다.
// == 열려있는 상태를 1로 만든다.
// ** VCC에 저항 달아주기
// On (0,Low) / Off (1,HIGH)

int LED_Red = 13;
int button_Push = 8;

void setup() {
  Serial.begin(9600);
  pinMode(LED_Red, OUTPUT);
  pinMode(button_Push, INPUT_PULLUP);   // ** 스위치(풀업) : INPUT_PULLUP
}

void loop() {
  int readValue = digitalRead(button_Push);   // 스위치 : 디지털값
  Serial.println(readValue);
  
  //  스위치가 열려있는 상태 : 누르지 않은 상태 == 1
  if(readValue == HIGH) {         
    digitalWrite(LED_Red, HIGH);    // LED 켜지기
  } 
   //  스위치가 닫혀있는 상태 : 누른 상태 == 0
  else {                         
    digitalWrite(LED_Red, LOW);
  }

}

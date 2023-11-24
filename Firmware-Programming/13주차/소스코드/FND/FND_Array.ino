// FND (2차원 배열) 출력
// 0~9 출력

int ON = LOW;
int OFF = HIGH;
int digits[10][8]= {
  {OFF,OFF,OFF,OFF,OFF,OFF,ON,ON},
  {ON,OFF,OFF,ON,ON,ON,ON,ON},
  {OFF,OFF,ON,OFF,OFF,ON,OFF,ON},
  {OFF,OFF,OFF,OFF,ON,ON,OFF,ON},
  {ON,OFF,OFF,ON,ON,OFF,OFF,ON},
  {OFF,ON,OFF,OFF,ON,OFF,OFF,ON},
  {OFF,ON,OFF,OFF,OFF,OFF,OFF,ON},
  {OFF,OFF,OFF,ON,ON,OFF,ON,ON},
  {OFF,OFF,OFF,OFF,OFF,OFF,OFF,ON},
  {OFF,OFF,OFF,OFF,ON,OFF,OFF,ON}
};
int pins[] = {2,3,4,5,6,7,8,9,};

void setup() {
  Serial.begin(9600);
  for(int i=0 ; i < 8 ; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {

  for(int i=0 ; i <=9; i++) {
    for(int j=0; j <8; j++) {
      digitalWrite(pins[j], digits[i][j]);
    }
    delay(1000);
  }
}

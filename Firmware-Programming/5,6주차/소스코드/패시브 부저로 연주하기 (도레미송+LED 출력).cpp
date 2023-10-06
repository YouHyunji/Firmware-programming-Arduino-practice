// 패시브 부저로 연주하기 ( 도레미송 ) + LED
// 주파수 활용

#define C4  262  //도 ( 4옥타브 )
#define C4s 277 //도#  ( s:#) 
#define D4  294 //레
#define D4s 311 //레#
#define E4  330 //미
#define F4  349 //파
#define F4s 370
#define G4  392 //솔
#define G4s 415
#define A4  440
#define A4s 466
#define B4  494
#define C5  523 //도(5옥타브)

int pin_Passive = 10;
int LED_C4 = 11;
int LED_D4 = 12;
int LED_E4 = 13;
int LED_F4 = 9;   //파

int melody[] = { C4, D4, E4,C4,E4,C4,E4,0, D4, E4, F4, F4, E4, D4, F4, 0 };
               //  E4,F4,G4,E4,G4,E4,G4,0,   F4,G4,A4,A4,G4,F4,G4,0 }; //계이름 (도레미), 0은 쉼표
int duration_s[] = {4.5,8,4.5,8,4,4,2,4, 4.5,8,8,8,8,8,2,4};
                   // 4,8,4,8,4,4,2,4,  4,8,8,8,8,8,2,4 };   // 음 길이(박자)
int LED_s[] = {LED_C4, LED_D4, LED_E4, LED_C4,LED_E4,LED_C4,LED_E4,-1,
               LED_D4,LED_E4,LED_F4,LED_F4,LED_E4,LED_D4,LED_F4, -1};      // LED    // LED

void setup() {
    pinMode(pin_Passive, OUTPUT);
    pinMode(LED_C4, OUTPUT);
    pinMode(LED_D4, OUTPUT);
    pinMode(LED_E4, OUTPUT);
    pinMode(LED_F4, OUTPUT);
}

void loop() {
  for(int sounds = 0; sounds < 15; sounds++) {
   
    //음 켜짐
      int Duration = 1000/duration_s[sounds];
      tone(pin_Passive, melody[sounds]);
      digitalWrite(LED_s[sounds],HIGH); //LED
      delay(Duration);
      
    // 음 꺼짐
      digitalWrite(LED_s[sounds],LOW);  //LED
      int pauseSound = Duration * 1.3;  
      noTone(pin_Passive);
      delay(pauseSound);
    
  }
}

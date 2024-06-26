# Firmware-programming-Arduino-practice
펌웨어 프로그래밍 수업에서 아두이노를 활용한 실습 내용을 모아둔 저장소입니다.

<br><br>

## ✏️ 실습 내용

### 2주차 ( 2023. 09. 08 ) : Serial Communication & LED
- Serial Monitor에서 입력받은 데이터에 따라 LED 출력
- S.O.S 모스부호를 LED로 출력

### 3주차 ( 2023. 09. 15 ) : LED & 가변저항
- 아날로그 값으로 LED 출력
- 시리얼 모니터에 입력되는 값에 따라 여러 개의 LED 출력
- 가변저항으로 LED 출력
- 가변저항으로 RGB LED 출력 ( 색 섞기 )


### 4주차 ( 2023. 09. 22 ) : 블루투스 모듈 & 서보모터
- 블루투스 모듈 : 앱으로 LED 제어 ( 버튼 4개로 2개의 LED 제어 )
- 블루투스 모듈 : 앱으로 LED + 서보모터 제어 (디지털 출력 & 아날로그 출력)
- 서보모터 기초 제어 실습
- 서보모터 : 가변저항 값을 입력받아 출력


### 5주차 ( 2023. 09. 29 ) : 피에조 부저
- Active & Passive 부저 작동
- Passive 부저: 도레미송 연주 + LED 출력


### 6주차 ( 2023. 10. 06 ) :  초음파 센서
- 초음파 센서 : 거리 측정 후 시리얼 모니터에 출력
- 초음파 센서 : 거리 측정 후 부저 & LED 점멸


### 7주차 ( 2023. 10. 13 ) : 스위치
- 풀업 & 풀다운 연결
- 스위치 2개로 LED 2개 출력 (풀다운)
- 스위치 3개로 RGB LED 출력 (풀업)
- 스위치로 패시브 부저 소리 출력


### 9주차 ( 2023. 10. 27 ) : TTS & 음성인식
- TTS (Text To Speech) : 텍스트 입력(점등&소등)에 따라 LED 출력
- TTS (Text To Speech) : 텍스트 입력(각도)에 따라 서보모터 출력
- 음성인식 : 음성 입력(점등&소등)에 따라 LED 출력
- 음성인식 : 음성 입력(색깔)에 따라 RGB LED 출력
- TTS + 음성인식 : 자신이 말한 문장을 텍스트와 음성으로 출력


### 10주차 ( 2023. 11. 03 ) : 위치센서 & Canvas
- 위치센서 : 스마트폰을 기울였을 때, 각도(x,y,z축)를 스마트폰 화면에 출력
- 위치센서 : 스마트폰 각도 값에 따라 LED & 서보모터 출력
- 위치센서 : 스마트폰 각도 값에 따라 RGB LED 출력 ( 노랑색에서 흰색으로 변화 )
- 위치센서 : 나침반 구현 & 위치마다(동서남북) LED 출력, 화면 색깔 교체
- Canvas : 기본 개념 ( 사진 추가, Ball 추가 )
- 위치센서 + Canvas : 스마트폰을 기울였을 때, x축 방향으로 Ball이 동작 


### 11주차 ( 2023. 11. 10 ) : 조이스틱
- 조이스틱 기본 동작 : x축, y축, 스위치 클릭 여부를 Serial 모니터에 출력
- 조이스틱 : 방향(좌우)과 스위치 클릭 여부에 따라 LED 3개(2+1) 출력
- 조이스틱 : 방향(상하좌우)과 스위치 클릭 여부에 따라 LED 5개(4+1) 출력
- 조이스틱 : 방향과 스위치 클릭 여부에 따라 RGB LED 출력
- 조이스틱 : 조이스틱 x축 입력 값으로 서보모터 출력


### 12주차 ( 2023. 11. 17 ) : 리모콘
- 리모콘 기본 동작 : 버튼에 값을 지정하여 Serial 모니터에 출력
- 리모콘 버튼 2개로 LED 2개 출력
- 리모콘 버튼 ( 1~9번 버튼 )으로 RGB LED 출력
- 리모콘 버튼 ( 방향키 )로 서보모터 출력


### 13주차 ( 2023. 11. 24 ) : 레이저 모듈 & FND
- 레이저 기본 동작 : 스위치(풀업저항)를 눌렀을 때 레이저 출력
- FND 기본 동작 : 2차원 배열로 값 미리 선언하여 숫자 0~9 출력해보기
- FND : 메서드로 구현하여 원하는 숫자 출력하기
- FND : 스위치(풀업저항) 3개를 각각 눌렀을 때, 숫자 3,6,9를 출력
- FND : 초음파 센서로 측정한 거리마다 FND에 다른 숫자(0,1,2) 출력


### 14주차 ( 2023. 12. 01 ) : MQ-3 & CdS 센서
- MQ-3 ( 알코올 감지 센서 ) 기본 동작 : 측정 결과를 Serial 모니터에 출력
- MQ-3 : 설정한 값을 초과하면 LED 출력 
- MQ-3 : 측정 값에 따라 RGB LED 출력
        ( 위험 : 빨강 / 주의 : 초록/ 양호 : 파랑 )
- CdS 센서 (일반 소자 & 측정 모듈) 기본 동작 : 측정 결과를 Serial 모니터에 출력
- CdS 센서 : 어두우면 LED 점등, 밝으면 LED 소등
- CdS 센서 : 밝기에 따라 RGB LED 출력
            ( 매우 밝음 : 빨강 / 보통 : 초록 / 어두움 : 파랑 )


### Final Test : 총 3문제, 만점
#### 1번 문제
- 1-1 (TTS) : 앱에서 입력 창에 '레이저 발사','레이저 점멸', '레이저 중지' 입력 시, 각각 다르게 레이저 출력
- 1-2 (음성 인식) : '레이저 발사','레이저 점멸', '레이저 중지'라고 말했을 때, 각각 다르게 레이저 출력
- 1-3 (위치센서) : 휴대폰을 눕혀놓은 상태에서 들어올렸을 때, 레이저 출력
#### 2번 문제
- 2 ( JoyStick & FND ) : 조이스틱을 상하좌우로 움직였을 때와 중심에 뒀을 때, FND와 Serial 모니터가 각각 다른 숫자를 출력
#### 3번 문제
- 3 ( 리모콘 ) : 리모콘으로 각각 0~9번 버튼을 눌렀을 때, LED & RGB LED & 레이저를 출력 ( ON/OFF 모두 )

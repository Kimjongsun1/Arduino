#define TRIG1 3 // 초음파 센서 1번 Trig 핀 번호
#define ECHO1 4 // 초음파 센서 1번 ECHO 핀 번호


void setup() 
{
  // put your setup code here, to run once:
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);

  Serial.begin(115200); //통신속도를 11520으로 정의함
}
long sonar1(void) // 초음파 센서 1번 측정 함수
{
  long duration, distance;
  digitalWrite(TRIG1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1, LOW);
  duration = pulseIn(ECHO1, HIGH);
  distance = (  (float)(340*duration)/1000)/2;
  return distance;
}

void loop() 
{
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(TRIG1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1, LOW);
  duration = pulseIn(ECHO1, HIGH);
  distance = (  (float)(340*duration)/1000)/2;
 //Serial.print("Duration: ");
 // Serial.println(duration);
  Serial.print("distance: ");
  Serial.println( sonar1() );
  delay(500);
}

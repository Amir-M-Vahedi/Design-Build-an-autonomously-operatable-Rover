//LEDs
int LEDForward=16;
int LEDRight=17;
int LEDleft=19;
int LEDBackward=18;
//L298& motor inf
//channel A
int IN1=12,IN2=13;
int ENA=10;
//channel B
int IN3=2,IN4=3;
int ENB=11;
int motorspeed1=0;
int motorspeed2=0;
//UltraSnoics
int triq_f=4,echo_f=5;
int triq_b=6,echo_b=7;
float duration_f, cm_f,duration_b, cm_b;
//Specify digital pin on the Arduino that the positive lead of piezo buzzer is attached.
int piezoPin = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //LEDs
  pinMode(LEDForward,OUTPUT);
  pinMode(LEDRight,OUTPUT);
  pinMode(LEDleft,OUTPUT);
  pinMode(LEDBackward,OUTPUT);
  pinMode(triq_f,OUTPUT);
  pinMode(triq_b,OUTPUT);
  pinMode(echo_f,INPUT);
  pinMode(echo_b,INPUT);
//L298 setup
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
  digitalWrite(ENA,LOW);//disabling motor
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);
  digitalWrite(ENB,LOW);//disabling motor
  digitalWrite(LEDForward,LOW);
  digitalWrite(LEDRight,LOW);
  digitalWrite(LEDleft,LOW);
  digitalWrite(LEDBackward,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triq_f,LOW);
  delayMicroseconds(2);
  digitalWrite(triq_f,HIGH);
  delayMicroseconds(5);
  digitalWrite(triq_f,LOW);
  duration_f=pulseIn(echo_f,HIGH);
  cm_f =(( duration_f/29)/2);
  
  digitalWrite(triq_b,LOW);
  delayMicroseconds(2); 
  digitalWrite(triq_b,HIGH);
  delayMicroseconds(5);
  digitalWrite(triq_b,LOW);
  duration_b=pulseIn(echo_b,HIGH);
  cm_b =(( duration_b/29)/2);

  Serial.println(cm_f);
  Serial.println(cm_b);
  delay(100); 
  if(cm_f<20 || cm_b<20)
  {
    Alarm();
  }
  
char dir; 
if(Serial.available() > 0)
{
  dir=Serial.read();
  switch (dir)
  {
   case '1':
    MoveForward();
    break;
   case 'a':
    AvoidDamage();
    break;
   case 'b':
    MoveBackward();
    break;
   case 'l':
    turnLeft();
    break;
   case 'r':
    turnRight();
    break;  
  }
}
if(cm_f<15 || cm_b<15)
  {
    AvoidDamage();
  }
}
//Function For Turn to Right
void turnRight()
{
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
   motorspeed1=200;
   motorspeed2=200;
   analogWrite(ENA,motorspeed1);
   analogWrite(ENB,motorspeed2);
  //LED
  digitalWrite(LEDForward,LOW);
  digitalWrite(LEDRight,HIGH);
  digitalWrite(LEDleft,LOW);
  digitalWrite(LEDBackward,LOW);
}

//Function For Turn to Left
void turnLeft()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN4,HIGH);
  digitalWrite(IN3,LOW);
  motorspeed1=200;
  motorspeed2=200;
  analogWrite(ENA,motorspeed1);
  analogWrite(ENB,motorspeed2);
  //LED
  digitalWrite(LEDForward,LOW);
  digitalWrite(LEDRight,LOW);
  digitalWrite(LEDleft,HIGH);
  digitalWrite(LEDBackward,LOW);  
}

//Function For Moving Forward
void MoveForward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(IN3,LOW);
  motorspeed1=130;
  motorspeed2=130;
  analogWrite(ENA,motorspeed1);
  analogWrite(ENB,motorspeed2);
  //LED
  digitalWrite(LEDForward,HIGH);
  digitalWrite(LEDRight,LOW);
  digitalWrite(LEDleft,LOW);
  digitalWrite(LEDBackward,LOW);
    
}
//Function For Moving Backward
void MoveBackward()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(IN3,HIGH);
  motorspeed1=150;
  motorspeed2=150;
  analogWrite(ENA,motorspeed1);
  analogWrite(ENB,motorspeed2);
  //LED
  digitalWrite(LEDForward,LOW);
  digitalWrite(LEDRight,LOW);
  digitalWrite(LEDleft,LOW);
  digitalWrite(LEDBackward,HIGH);  
}

void AvoidDamage()
{
      digitalWrite(ENA,LOW);
      digitalWrite(ENB,LOW);
      //LED
      digitalWrite(LEDForward,LOW);
      digitalWrite(LEDRight,LOW);
      digitalWrite(LEDleft,LOW);
      digitalWrite(LEDBackward,LOW);
  }
void Alarm()
{
      tone(piezoPin, 1000, 600);
      delay(1000);
      digitalWrite(piezoPin,LOW);
      delay(100);
  }

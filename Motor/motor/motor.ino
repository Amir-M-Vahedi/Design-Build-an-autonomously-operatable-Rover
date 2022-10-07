//L298& motor inf
//channel A
int IN1=12,IN2=13;
int ENA=10;
//channel B
int IN3=0,IN4=1;
int ENB=11;
int motorspeed1=0;
int motorspeed2=0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  MoveForward();



  
}
//Function For Turn to Right
void turnRight()
{
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
   motorspeed1=240;
   motorspeed2=240;
   analogWrite(ENA,motorspeed1);
   analogWrite(ENB,motorspeed2);
  
}

//Function For Turn to Left
void turnLeft()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN4,HIGH);
  digitalWrite(IN3,LOW);
  motorspeed1=240;
  motorspeed2=240;
  analogWrite(ENA,motorspeed1);
  analogWrite(ENB,motorspeed2);  
}

//Function For Moving Forward
void MoveForward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(IN3,LOW);
  motorspeed1=100;
  motorspeed2=100;
  analogWrite(ENA,motorspeed1);
  analogWrite(ENB,motorspeed2);

  

}

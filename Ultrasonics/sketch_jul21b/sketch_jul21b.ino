//Front Left is forward
//Front Right is Right
//Back Left is Left
//Back Right is Right
int triq_fl=2,echo_fl=3,triq_fr=4,echo_fr=5;
int triq_bl=6,echo_bl=7,triq_br=8,echo_br=9;
float duration_fl, cm_fl,duration_fr, cm_fr,duration_bl, cm_bl,duration_br, cm_br;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(triq_fl,OUTPUT);
  pinMode(triq_fr,OUTPUT);
  pinMode(triq_bl,OUTPUT);
  pinMode(triq_br,OUTPUT);
  pinMode(echo_fl,INPUT);
  pinMode(echo_fr,INPUT);
  pinMode(echo_bl,INPUT);
  pinMode(echo_br,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triq_fl,LOW);
  delayMicroseconds(2);
  digitalWrite(triq_fl,HIGH);
  delayMicroseconds(5);
  digitalWrite(triq_fl,LOW);
  duration_fl=pulseIn(echo_fl,HIGH);
  cm_fl =(( duration_fl/29)/2);
  
  
  digitalWrite(triq_fr,LOW);
  delayMicroseconds(2);
  digitalWrite(triq_fr,HIGH);
  delayMicroseconds(5);
  digitalWrite(triq_fr,LOW);
  duration_fr=pulseIn(echo_fr,HIGH);
  cm_fr =(( duration_fr/29)/2);
  
  digitalWrite(triq_bl,LOW);
  delayMicroseconds(2); 
  digitalWrite(triq_bl,HIGH);
  delayMicroseconds(5);
  digitalWrite(triq_bl,LOW);
  duration_bl=pulseIn(echo_bl,HIGH);
  cm_bl =(( duration_bl/29)/2);

  digitalWrite(triq_br,LOW);
  delayMicroseconds(2); 
  digitalWrite(triq_br,HIGH);
  delayMicroseconds(5);
  digitalWrite(triq_br,LOW);
  duration_br=pulseIn(echo_br,HIGH);
  cm_br =(( duration_br/29)/2);
  
  
//  Serial.print("distance Front Left = ");
  Serial.println(cm_fl);
//  Serial.print(" cm");
//  Serial.print("\n");
  
//  Serial.print("distance Front Right = ");
  Serial.println(cm_fr);
//  Serial.print(" cm");
//  Serial.print("\n");

//  Serial.print("distance Back Left = ");
  Serial.println(cm_bl);
//  Serial.print(" cm");
//  Serial.print("\n");
  
//  Serial.print("distance Back Right = ");
  Serial.println(cm_br);
//  Serial.print(" cm");
//  Serial.print("\n");
  delay(400); 
  if(Serial.available() > 0)
  {
    if(Serial.read() == '1')
    {
      digitalWrite(13,HIGH);
      delay(2000);
    }
  }  

    else
    {
      digitalWrite(13,LOW);
    }



}
//void AvoidDamage()
//{
//  if(distance<=12)
//  {
//    digitalWrite(ENA,LOW);
//    digitalWrite(ENB,LOW);
//  }

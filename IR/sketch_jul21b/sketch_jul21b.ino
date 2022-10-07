
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(9,OUTPUT);

}

void loop() {
 digitalWrite(9,HIGH);
 
 Serial.println(digitalRead(8));
 delay(200);

}

void speaker_init()
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(5,HIGH);
  delay(1500);
  digitalWrite(5,LOW);
  delay(9000);
  digitalWrite(6,HIGH);
  delay(2000);
  digitalWrite(6,LOW);
}


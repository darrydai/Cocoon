void speaker_init()
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(4,HIGH);
  delay(1500);
  digitalWrite(4,LOW);
  delay(9000);
  digitalWrite(5,HIGH);
  delay(2000);
  digitalWrite(5,LOW);
}

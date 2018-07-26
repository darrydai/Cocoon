void information()
{
  Serial.print(F("playerStatus:"));
  Serial.println(playerStatus);
  Serial.print(F("soundOneStatus"));
  Serial.println(soundOneStatus);
  Serial.print(F("fadedown:"));
  Serial.println(fadedown);
  Serial.print(F("speakStatus:"));
  Serial.println(speakStatus); 
}

void wakeupSpeaker(int _hour,int _minute)
{
  if(currentTime_hour==_hour&&currentTime_min==_minute)
  {
    if(speakStatus==false)
    {
      digitalWrite(4,HIGH);
      delay(1500);
      digitalWrite(4,LOW);
      delay(9000);
      digitalWrite(5,HIGH);
      delay(2000);
      digitalWrite(5,LOW);
      speakStatus=true;
    }
  }
}

void mainSound(int _hour,int _minute)
{
  if(_hour==currentTime_hour)
  {
    if(_minute==currentTime_min)
    {
      if(soundOneStatus==false)
      {
        myDFPlayer.stop();
        soundPlay(1,25);
        playerStatus=true;
        soundOneStatus=true;
      }
    }
  }
}

void keepTheSpkOn(int _time1,int _time2,int _minute)
{
  if(currentTime_hour >= _time1 && currentTime_hour <= _time2)
  {
    if(currentTime_min> _minute || currentTime_min< _minute)
    {
      if(playerStatus!=true)
      {
        myDFPlayer.stop();
        soundPlay(2,1);
        playerStatus=true;
        Serial.println(F("normalsound"));
      }
    }
  }
}


void soundPlay(int soundNumber,int soundVolume)
{
  char* sList[]={"playSound_1","playSound_2"};
  myDFPlayer.stop();
  myDFPlayer.volume(soundVolume);
  myDFPlayer.playMp3Folder(soundNumber);
  if(debugStatus==true)
  {
    Serial.println(sList[soundNumber-1]);
  }
}

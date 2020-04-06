//void wakeupSpeaker(int _hour,int _minute)
//{
//  if(currentTime_hour==_hour&&currentTime_min==_minute)
//  {
//    if(speakStatus==false)
//    {
//      digitalWrite(4,HIGH);
//      delay(1500);
//      digitalWrite(4,LOW);
//      delay(9000);
//      digitalWrite(5,HIGH);
//      delay(2000);
//      digitalWrite(5,LOW);
//      speakStatus=true;
//    }
//  }
//}

void mainSound(int _hour,int _minute)
{
  if(_hour==currentTime_hour)
  {
    if(_minute==currentTime_min)
    {
      if(soundOneStatus==false)
      {
        myDFPlayer.stop();
        playerStatus=true;
        soundOneStatus=true;
        soundPlay(1,25);
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
      if(soundOneStatus!=true&&playerStatus!=true)
      {
        delay(10);
        myDFPlayer.stop();
        playerStatus=true;
        delay(10);
        soundPlay(2,1);
        Serial.println(F("play_normalsound"));
      }
    }
  }
}


void soundPlay(int soundNumber,int soundVolume)
{
  char* sList[]={"playSound_1","playSound_2"};
  myDFPlayer.stop();
  myDFPlayer.volume(soundVolume);
  delay(10);
  myDFPlayer.playMp3Folder(soundNumber);
  if(debugStatus==true)
  {
    Serial.println(sList[soundNumber-1]);
  }
}

void timeChecker()
{
  DateTime now = rtc.now();
  char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  currentTime_hour=now.hour();
  currentTime_min=now.minute();
  if(debugStatus==true)
  {
    Serial.print(F("current_Time:"));
    Serial.print(currentTime_hour);
    Serial.println(currentTime_min);
    Serial.print(F("calendar:"));
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();   
  }
}

void information()
{
  Serial.print(F("playerStatus:"));
  Serial.println(playerStatus);
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

void modeSelect(int _hour,int _minute)
{
  switch(_hour)
  {
    case 1 ... 11:
      lightModeSwitch(4);
      speakStatus=false;
      delay(100);
      break;
    case 12 ... 17:
      if(_minute==30)
      {
        if(soundOneStatus==false)
        {
          myDFPlayer.stop();
          soundPlay(1,20);
          Serial.println(F("sound one on on time"));
          playerStatus=true;
          soundOneStatus=true;
        }
      }
      else
      {
        soundOneStatus==false;
        if(playerStatus==true)
        {
          //soundOneStatus=false;
        }
        else
        {
          if(_minute>30||_minute<30)
          {
            myDFPlayer.stop();
            soundPlay(2,1);
            Serial.println(F("normalsound_day"));
            playerStatus=true;
          }
        }
      }
      break;
    case 18 ... 20:
      if(_minute==30)
      {
        if(soundOneStatus==false)
        {
          //myDFPlayer.stop();
          soundPlay(1,20);
          Serial.println(F("sound one on on time"));
          playerStatus=true;
          soundOneStatus=true;
          fadedown=false;
        }
        lightModeSwitch(2);
      }
      else
      {
        soundOneStatus=false;
        if(playerStatus==true)
        {
          break;
        }
        else
        {
          if(fadedown==true)
          {
            lightModeSwitch(1);
          }
          else
          {
            lightModeSwitch(3);
          }
          if(_minute>30||_minute<30)
          {
            //myDFPlayer.stop();
            soundPlay(2,1);
            Serial.println(F("normalsound_night"));
            playerStatus=true;
          }
        }
      }
      break;
    case 21:
      if(_minute==00)
      {
        if(soundOneStatus==false)
        {
          //myDFPlayer.stop();
          soundPlay(1,20);
          playerStatus=true;
          soundOneStatus=true;
          fadedown=false;
        }
        lightModeSwitch(2);
      }
      else
      {
        soundOneStatus=false;
        if(playerStatus==true)
        {
          break;
        }
        else
        {
          if(fadedown==true)
          {
            lightModeSwitch(1);
          }
          else
          {
            lightModeSwitch(3);
          }
          if(_minute>30||_minute<30)
          {
            myDFPlayer.stop();
            soundPlay(2,1);
            Serial.println(F("normalsound_night"));
            playerStatus=true;
          }
        }
      }
      break;
    case 22 ... 23:
      if(_minute==30)
      {
        if(soundOneStatus==false)
        {
          //myDFPlayer.stop();
          soundPlay(1,20);
          Serial.println(F("sound one on on time"));
          playerStatus=true;
          soundOneStatus=true;
          fadedown=false;
        }
        lightModeSwitch(2);
      }
      else
      {
        soundOneStatus=false;
        if(playerStatus==true)
        {
          break;
        }
        else
        {
          if(fadedown==true)
          {
            lightModeSwitch(1);
          }
          else
          {
            lightModeSwitch(3);
          }
          if(_minute>30||_minute<30)
          {
            soundPlay(2,1);
            Serial.println(F("normalsound_night"));
            playerStatus=true;
          }
        }
      }
      break;
      case 0:
      if(_minute==30)
      {
        if(soundOneStatus==false)
        {
          //myDFPlayer.stop();
          soundPlay(1,20);
          Serial.println(F("sound one on on time"));
          playerStatus=true;
          soundOneStatus=true;
          fadedown=false;
        }
        lightModeSwitch(2);
      }
      else
      {
        soundOneStatus=false;
        if(playerStatus==true)
        {
          break;
        }
        else
        {
          if(fadedown==true)
          {
            lightModeSwitch(1);
          }
          else
          {
            lightModeSwitch(3);
          }
            soundPlay(2,1);
            Serial.println(F("normalsound_night"));
            playerStatus=true;
        }
      }
      break;
  }
}

void soundPlay(int soundNumber,int soundVolume)
{
  char* songList[]={"playSound_1","playSound_2"};
  myDFPlayer.volume(soundVolume);
  myDFPlayer.playMp3Folder(soundNumber);
  if(debugStatus==true)
  {
    Serial.println(songList[soundNumber-1]);
  }
}

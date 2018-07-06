void timeChecker()
{
  DateTime now = rtc.now();
  currentTime_hour=now.hour();
  currentTime_min=now.minute();
  if(debugStatus==true)
  {
    Serial.print(F("current_Time:"));
    Serial.print(currentTime_hour);
    Serial.println(currentTime_min);
    Serial.print(F("calendar"));
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
//    Serial.print(F("player_State:"));
//    Serial.println(player_State);
  }
}

void funtionSelect(uint8_t _hour,uint8_t _minute)
{
  switch (_hour)
  {
    case 19:
      switch(_minute)
      {
        case 57:
          if(soundOneStatus==false)
          {
            myDFPlayer.stop();
            soundPlay(1,15);
            Serial.println(F("sound on on time"));
            soundOneStatus=true;
            songStatus=true;
          }
        break;
        default:
          if(songStatus==true)
          {
            break;
          }
          else if(songStatus==false&&soundOneStatus==true)
          {
            myDFPlayer.stop();
            soundPlay(1,1);
            Serial.println(F("normalstatus_"));
            songStatus=true;
          }
          break;
      }
     break;
    case 20:
      switch(_minute)
      {
        case 25:
          if(soundOneStatus==false)
          {
            myDFPlayer.stop();
            soundPlay(1,15);
            lightModeSwitch(2);
            Serial.println(F("sound on on time"));
            soundOneStatus=true;
            songStatus=true;
          }
        break;
        default:
          if(songStatus==true)
          {
            break;
          }
          else if(songStatus==false&&soundOneStatus==true)
          {
            /*
             If the sound is finished playing,fadedown the light,
             and next loop is fade_normalMode.
            */
            if(fadedown==true)
            {
              lightModeSwitch(1);
            }
            else
            {
              lightModeSwitch(3);
            }
            myDFPlayer.stop();
            soundPlay(1,1);
            Serial.println(F("normalstatus_"));
            songStatus=true;
          }
          break;
      }
      break;
    case 21:
      lightModeSwitch(1);
      if(songStatus==true)
      {
        break;
      }
      else if(songStatus==false)
      {
        soundPlay(1,1);
        Serial.println(F("normalstatus_other"));
        songStatus=true;
      }
      break;    
    default:
      if(songStatus==true)
      {
        break;
      }
      else if(songStatus==false)
      {
        soundPlay(1,1);
        Serial.println(F("normalstatus_other"));
        songStatus=true;
      }
      break;
  }
}  

void soundPlay(int soundNumber,int soundVolume)
{
  char* songList[]={"playSound_1","playSound_2"};
  //myDFPlayer.stop();
  delay(100);
  myDFPlayer.volume(soundVolume);
  myDFPlayer.playMp3Folder(soundNumber);
  if(debugStatus==true)
  {
    Serial.println(songList[soundNumber-1]);
  }
}

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
    Serial.print(F("songStatus:"));
    Serial.println(songStatus);
    Serial.print(F("songOneStatus:"));
    Serial.println(soundOneStatus);
    Serial.print(F("fadedown:"));
    Serial.println(fadedown);
    Serial.print(F("speakStatus:"));
    Serial.println(speakStatus);    
  }
}

void wakeupSpeaker()
{
  digitalWrite(4,HIGH);
  delay(1500);
  digitalWrite(4,LOW);
  delay(9000);
  digitalWrite(5,HIGH);
  delay(2000);
  digitalWrite(5,LOW);
  Serial.println(F("speaker is trun on"));
}

void modeSelect(int _hour,int _minute)
{
  switch(_hour)
  {
    case 1 ... 11:
      lightModeSwitch(4);
      speakStatus=false;
      break;
    case 12 ... 17:
      if(_minute==27&&speakStatus==false)
      {
        wakeupSpeaker();
        speakStatus=true;
      }
      if(_minute==30)
      {
        if(soundOneStatus==false)
        {
          //myDFPlayer.stop();
          soundPlay(1,20);
          Serial.println(F("sound one on on time"));
          songStatus=true;
          soundOneStatus=true;
        }
      }
      else
      {
        soundOneStatus==false;
        if(songStatus==true)
        {
          
        }
        else
        {
          soundPlay(2,1);
          Serial.println(F("normalsound_day"));
          songStatus=true;
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
          songStatus=true;
          soundOneStatus=true;
          fadedown=false;
        }
        lightModeSwitch(2);
      }
      else
      {
        soundOneStatus=false;
        if(songStatus==true)
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
            songStatus=true;
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
          Serial.println(F("sound one on on time"));
          songStatus=true;
          soundOneStatus=true;
          fadedown=false;
        }
        lightModeSwitch(2);
      }
      else
      {
        soundOneStatus=false;
        if(songStatus==true)
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
            songStatus=true;
          }
        }
      }
      break;
    case 22 ... 24:
      if(_minute==30)
      {
        if(soundOneStatus==false)
        {
          //myDFPlayer.stop();
          soundPlay(1,20);
          Serial.println(F("sound one on on time"));
          songStatus=true;
          soundOneStatus=true;
          fadedown=false;
        }
        lightModeSwitch(2);
      }
      else
      {
        soundOneStatus=false;
        if(songStatus==true)
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
            songStatus=true;
          }
        }
      }
      break;
  }
}
//    if(_hour==hTimeSlot[c]&&_hour>=18)
//    {
//      switch(_minute)
//      {
//        case 30:
//          if(soundOneStatus==false)
//          {
//            myDFPlayer.stop();
//            soundPlay(1,20);
//            delay(1);
//            Serial.println(F("sound on on time,light mode 2"));
//            songStatus=true;
//            fadedown=false;
//            soundOneStatus=true;
//          }
//          lightModeSwitch(2);
//          break;
//        default:
//          soundOneStatus=false;
//          if(songStatus==true)
//          {
//            break;
//          }
//          else
//          {
//            if(fadedown==true)
//            {
//              lightModeSwitch(1);
//            }
//            else
//            {
//              lightModeSwitch(3);
//            }
//            if(_minute>30||_minute<30)
//            {
//              myDFPlayer.stop();
//              soundPlay(2,1);
//              Serial.println(F("normalstatus_"));
//              songStatus=true;
//            }
//          }
//          break;
//        }
//    }      
//  }
//  switch (_hour)
//  {
//    case 12:
//      switch(_minute)
//      {
//        case 30:
//            myDFPlayer.stop();
//            soundPlay(1,20);
//            Serial.println(F("sound on on time"));
//            //soundOneStatus=true;
//            songStatus=true;
//          break;
//        default:
//          if(songStatus==true)
//          {
//            break;
//          }
//          else
//          {
//            if(_minute>55|| _minute<55)
//            {
//              myDFPlayer.stop();
//              soundPlay(2,1);
//              Serial.println(F("normalstatus_"));
//              songStatus=true;
//            }
//          }
//          break;
//      }
//     break;
//    case 20:
//      switch(_minute)
//      {
//        case 25:
//            myDFPlayer.stop();
//            soundPlay(1,20);
//            lightModeSwitch(2);
//            Serial.println(F("sound on on time"));
//            //soundOneStatus=true;
//            songStatus=true;
//        break;
//        default:
//          if(songStatus==true)
//          {
//            break;
//          }
//          else
//          {
//            /*
//             If the sound is finished playing,fadedown the light,
//             and next loop is fade_normalMode.
//            */
//            if(fadedown==true)
//            {
//              lightModeSwitch(1);
//            }
//            else
//            {
//              lightModeSwitch(3);
//            }
//            if(_minute>25||_minute<25)
//            {
//              myDFPlayer.stop();
//              soundPlay(2,1);
//              Serial.println(F("normalstatus_"));
//              songStatus=true;
//            }
//          }
//          break;
//      }
//      break;
//    case 21:
//      lightModeSwitch(1);
//      delay(100);
//      if(songStatus==true)
//      {
//        break;
//      }
//      else
//      {
//        myDFPlayer.stop();
//        soundPlay(2,1);
//        Serial.println(F("normalstatus_light"));
//        songStatus=true;
//      }
//      break;    
//    default:
//      if(songStatus==true)
//      {
//        break;
//      }
//      else
//      {
//        myDFPlayer.stop();
//        //myDFPlayer.reset();
//        delay(1);
//        soundPlay(2,1);
//        Serial.println(F("normalstatus_other"));
//        songStatus=true;
//      }
//      break;
//  }
//}  

void soundPlay(int soundNumber,int soundVolume)
{
  char* songList[]={"playSound_1","playSound_2"};
  //myDFPlayer.stop();
  //delay(100);
  myDFPlayer.volume(soundVolume);
  myDFPlayer.playMp3Folder(soundNumber);
  if(debugStatus==true)
  {
    Serial.println(songList[soundNumber-1]);
  }
}

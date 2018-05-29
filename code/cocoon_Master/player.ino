void playerInit()
{
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
}

void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      Standby=true;
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      Standby=false;
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

void fixed_Time_Airplay(uint8_t cheack_Time)
{
  switch (cheack_Time)
  {
    case 11:
      if(player_State!=cheack_Time)
      {
        myDFPlayer.stop();
        Serial.println(F("playSound_1"));
        myDFPlayer.volume(30);
        myDFPlayer.playMp3Folder(1);
      }
      else if(player_State==cheack_Time&&Standby!=true)
      {
        Standby=true;
        Serial.println(F("playSound_5"));
        myDFPlayer.volume(1);
        myDFPlayer.playMp3Folder(1);
      }      
      break;
    case 12:
      if(player_State!=cheack_Time)
      {
        myDFPlayer.stop();
        Serial.println(F("playSound_2"));
        myDFPlayer.volume(30);
        myDFPlayer.playMp3Folder(2);
      }
      else if(player_State==cheack_Time&&Standby!=true)
      {
        Standby=true;
        Serial.println(F("playSound_5"));
        myDFPlayer.volume(1);
        myDFPlayer.playMp3Folder(1);
      }  
      break;
    case 13:
      if(player_State!=cheack_Time)
      {
        incomingByte='a';
        Serial.println(F("light_On"));
        delay(10);
        Wire.beginTransmission(SLAVE_ADDRESS);
        Wire.write(incomingByte);
        Wire.endTransmission();
      }
      if(Standby!=true)
      {
        Standby=true;
        Serial.println(F("playSound_5"));
        myDFPlayer.volume(1);
        myDFPlayer.playMp3Folder(1);
      }
      break;
    case 14:
      if(player_State!=cheack_Time)
      {
        incomingByte='b';
        Serial.println(F("light_Off"));
        delay(10);
        Wire.beginTransmission(SLAVE_ADDRESS);
        Wire.write(incomingByte);
        Wire.endTransmission();
      }
      break;
    default:
      if(Standby!=true)
      {
        Standby=true;
        Serial.println(F("playSound_5"));
        myDFPlayer.volume(1);
        myDFPlayer.playMp3Folder(1);
      }
      else
      {
         break; 
      }
      break;
  }
  player_State=cheack_Time;
}  

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

void Timed_playback()
{
  DateTime now = rtc.now();
  cheack_Time=now.hour();
  Serial.println(cheack_Time);
  switch (cheack_Time)
  {
    case 12:
      Serial.println("playSound");
      myDFPlayer.volume(80);
      myDFPlayer.play(1);
      break;
    case 15:
      Serial.println("playSound");
      myDFPlayer.volume(50);
      myDFPlayer.play(1);
      break;
    case 17:
      Serial.println("playSound");
      myDFPlayer.volume(50);
      myDFPlayer.play(1);
      break;
    default:
      break;
  }
//  if(cheack_Time==13)
//  {
//    Serial.println("playSound");
//    myDFPlayer.volume(80);
//    myDFPlayer.play(1);
//  }
//  if(cheack_Time==)
//  {
//
//  }
//  if(cheack_Time==)
//  {
//    Serial.println("playSound");
//    myDFPlayer.volume(80);
//    myDFPlayer.play(1);
//  }
//  if(cheack_Time==)
//  {
//    Serial.println("playSound");
//    myDFPlayer.volume(80);
//    myDFPlayer.play(1);
//  }
//  if(cheack_Time==)
//  {
//    Serial.println("playSound");
//    myDFPlayer.volume(80);
//    myDFPlayer.play(1);
//  }    
//  if(cheack_Time==)
//  {
//    Serial.println("playSound");
//    myDFPlayer.volume(80);
//    myDFPlayer.play(1);
//  }
}  

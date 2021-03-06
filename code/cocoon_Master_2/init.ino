void mainInit()
{
  Wire.begin();         // join I2C bus as a Master
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  //myDFPlayer.setTimeOut(5000);
}

void speaker_init()
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  delay(9000);
  digitalWrite(5,HIGH);
  delay(2000);
  digitalWrite(5,LOW);
  //Serial.println(F("speaker is trun on"));
}

void playerInit()
{
  Serial.println();
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

void statusInit()
{
  debugStatus=false;
  playerStatus=false;
  soundOneStatus=false;
  ledFadedown=false;
}

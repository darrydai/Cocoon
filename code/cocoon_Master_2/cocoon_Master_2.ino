#include <Wire.h>
#include "RTClib.h"
#include "Timer.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define TX 3
#define RX 2

SoftwareSerial mySoftwareSerial(TX,RX);//TX RX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

RTC_DS3231 rtc;
Timer playerChackTime;
Timer lightChack;

const int SLAVE_ADDRESS = 1;
char serialRecive;

volatile int currentTime_hour,currentTime_min;

// The sound status, true is playing, false is Play Finished.
static boolean playerStatus;
static boolean debugStatus;
static boolean fadedown;
static boolean soundOneStatus;
static boolean speakStatus;

void setup() 
{  
  mainInit();
  delay(10);
  playerInit();
  delay(10);
  rtc_Init();
  delay(10);
  speaker_init();
  delay(10);
  statusInit();
  playerChackTime.every(1000,timeChecker);
  lightChack.every(100,light);
}

void loop() 
{
  if (myDFPlayer.available()) 
  {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); 
    delay(1);
  }
  playerChackTime.update();
  lightChack.update();
  B_09();
//  mainSound(11,35);
//  mainSound(11,50);
//  mainSound(12,00);
}

void serialEvent()
{
  serialRecive = Serial.read();
  Serial.println(serialRecive);
  switch(serialRecive)
  {
    case 'd': //debug switch
      debugStatus=debugStatus==true?false:true;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
      break;
    case 'i':
      information();
      break;
    case 'a':
      lightModeSwitch(1);
      break;
    case 'b':
      lightModeSwitch(4);
      break;
    case 's':
      soundPlay(1,15);
      
      break;
    case 't':
      myDFPlayer.stop();
      soundOneStatus=true;
      break;
    case 'l':
      lightModeSwitch(2);
      break;
    default:
      break;
  }
}

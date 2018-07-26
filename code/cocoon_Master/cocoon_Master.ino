#include <Wire.h>
#include "RTClib.h"
#include "Timer.h"
#include "SoftwareSerial.h"
#include "RTClib.h"
#include "DFRobotDFPlayerMini.h"

#define TX 3
#define RX 2

//const int SLAVE_ADDRESS = 1;
//char lightMode = 0;
char serialRecive;

SoftwareSerial mySoftwareSerial(TX,RX);//TX RX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);
//Timer tcb;
Timer playerChackTime;
Timer lightChack;

RTC_DS3231 rtc;
//char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

static int currentTime_hour,currentTime_min;

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
  rtc_Init();
  delay(10);
  playerInit();
  delay(10);
  speaker_init();
  delay(10);
  playerChackTime.every(1000,timeChecker);
  //lightChack.every(1000,light);
}

void loop() 
{
  playerChackTime.update();
  delay(1);
  if (myDFPlayer.available()) 
  {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); 
    //Print the detail message from DFPlayer to handle different errors and states.
    //delay(1);
  }
  delay(10);
//  mainSound(21,00);
//  mainSound(20,43);
//  light();
  modeSelect(currentTime_hour,currentTime_min);
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
    //light test,a is light on,b is light off  
    case 'a':
      lightModeSwitch(1);
      break;
    case 'b':
      lightModeSwitch(4);
      break;
    case 's':
      soundPlay(1,20);
      break;
    case 't':
      myDFPlayer.stop();
      break;
    case 'l':
      lightModeSwitch(2);
      break;
    default:
      break;
  }
}

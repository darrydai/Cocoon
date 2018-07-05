#include <Wire.h>
#include "RTClib.h"
#include "Timer.h"
#include "SoftwareSerial.h"
#include "RTClib.h"
#include "DFRobotDFPlayerMini.h"

const int SLAVE_ADDRESS = 1;
char lightMode = 0;

SoftwareSerial mySoftwareSerial(3,2);//TX RX
DFRobotDFPlayerMini myDFPlayer;

//Timer tcb;
Timer playerChackTime;

RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

volatile int currentTime_hour,currentTime_min;
volatile int player_State=0;

// true is playing,false is Play Finished.
static boolean songStatus;
static boolean debugStatus;
static boolean soundOneStatus;
static boolean soundTwoStatus;
static boolean fadedown;
char serialRecive;

void setup() 
{  
  mainInit();
  delay(10);
  rtc_Init();
  playerInit();
  speaker_init();
  delay(10);
  playerChackTime.every(1000,timeChecker);
}

void loop() 
{
  playerChackTime.update();
  if (myDFPlayer.available()) 
  {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
  funtionSelect(currentTime_hour,currentTime_min);
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
    //light test,a is light on,b is light off  
    case 'a':
      lightModeSwitch(1);
      break;
    case 'b':
      lightModeSwitch(4);
      break;
    case 's':
      soundPlay(1,1);
      break;
    case 't':
      myDFPlayer.stop();
      break;
    default:
      break;
  }
}

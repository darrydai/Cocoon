#include "Arduino.h"
#include "Timer.h"
#include "SoftwareSerial.h"
#include <Wire.h>
#include "RTClib.h"
#include "DFRobotDFPlayerMini.h"
#include "Adafruit_NeoPixel.h"

SoftwareSerial mySoftwareSerial(7,4);//TX RX
DFRobotDFPlayerMini myDFPlayer;

//Timer tcb;
Timer playerChackTime;

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
volatile int cheack_Time;
int state;

void setup () 
{
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  delay(3000); // wait for console opening
  speaker_init();
  playerInit();
  rtc_Init();
  delay(1000);
  playerChackTime.every(1000,Timed_playback);
}

void loop () 
{
  playerChackTime.update();
  if (myDFPlayer.available()) 
  {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
  rtc_CheackFuntion();
}

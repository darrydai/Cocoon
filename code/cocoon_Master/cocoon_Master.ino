#include <Wire.h>
#include "RTClib.h"
#include "Timer.h"
#include "SoftwareSerial.h"
#include "RTClib.h"
#include "DFRobotDFPlayerMini.h"

const int SLAVE_ADDRESS = 1;
char incomingByte = 0;

SoftwareSerial mySoftwareSerial(3,2);//TX RX
DFRobotDFPlayerMini myDFPlayer;

//Timer tcb;
Timer playerChackTime;

RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

volatile int current_Time;
volatile int player_State=0;
boolean Standby = false;

void setup() 
{  
  Wire.begin();         // join I2C bus as a Master
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  delay(1000);
  rtc_Init();
  playerInit();
  speaker_init();
  delay(1000);
  playerChackTime.every(1000,cheack_Hour);
}

void loop() 
{
  playerChackTime.update();
  if (myDFPlayer.available()) 
  {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
  fixed_Time_Airplay(current_Time);
  //rtc_CheackFuntion();
}

void serialEvent()
{
  // read one byte from serial port
  incomingByte = Serial.read();

  // send the received data to slave
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(incomingByte);
  Wire.endTransmission();
}

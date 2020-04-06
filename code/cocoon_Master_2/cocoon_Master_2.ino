#include <Wire.h>
#include <EEPROM.h>
#include "RTClib.h"
#include "Timer.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define TX 3
#define RX 2

SoftwareSerial mySoftwareSerial(TX,RX);//TX RX

DFRobotDFPlayerMini myDFPlayer;
RTC_DS3231 rtc;

Timer playerChackTime;
Timer lightChack;

const int SLAVE_ADDRESS = 1;

volatile int currentTime_hour,currentTime_min;

static boolean playerStatus;  // The sound status, true is playing, false is Play Finished.
static boolean debugStatus;
static boolean ledFadedown;
static boolean soundOneStatus;

char serialRecive;
char type;
int gNum;//small cocoon group number

void mainSound(int _hour,int _minute);

class cocoon
{
  public:
  void cocoonPlay(int cocoonSize);
  void cocoonPlay(int cocoonSize,int groups);
};

void cocoon::cocoonPlay(int _cocoonSize)
{
  switch (_cocoonSize)
  {
    case '1':
    {
      mainSound(13,00);
      mainSound(16,00);
      mainSound(21,00);
      break;
    }
    case '2':
    {
      
      break;
    }
    default:
      break;
  }
}

void cocoon::cocoonPlay(int _cocoonSize,int _groups)
{
  switch (_cocoonSize)
  {
    case 1:
    {
      mainSound(13,00);
      mainSound(16,00);
      mainSound(21,00);
      break;
    }
    case 2:
    {
      switch (_groups)
      {
        case 1:
        {
          mainSound(18,30);// S cocoon 1 3 5
          mainSound(20,30);
          mainSound(21,00);
          mainSound(22,30);
          break;
        } 
        case 2:
        {
          mainSound(19,30);// S cocoon 2 4 6
          mainSound(21,00);
          mainSound(21,30);
          mainSound(23,30);
          break;
        }
        default:
          break;
      }
      break;
    }
    default:
      break;
  }
}

cocoon cocoonPlayer;

void setup() 
{  
  mainInit();
  delay(10);
  speaker_init();
  delay(10);
  rtc_Init();
  delay(10);
  playerInit();
  delay(10);
  statusInit();
  playerChackTime.every(1000,timeChecker);
  lightChack.every(1000,light);
}

void loop() 
{
  if (myDFPlayer.available()) 
  {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); 
    delay(1);
  }
  type=EEPROM.read(1);
  gNum=EEPROM.read(2);
  playerChackTime.update();
  lightChack.update();
  switch (type)
  {
    case'b':
      cocoonPlayer.cocoonPlay(1);
      break;
    case 's':
      switch(gNum)
      {
        case 1:
          cocoonPlayer.cocoonPlay(2,1);
          keepTheSpkOn(7,23,30);
          break;
        case 2:
          cocoonPlayer.cocoonPlay(2,2);
          keepTheSpkOn(7,23,30);
          break;
      }
      break;
    default:
      Serial.println();
      Serial.println(F("Please set cocoon type!!"));
      Serial.println(F("b is big cocoon,s is small cocoon"));
      Serial.print(F("type="));
      while(1)
      {
        serialRecive=Serial.read();
        if(serialRecive=='b'||serialRecive=='s')
        {
          EEPROM.update(1,serialRecive);
          Serial.println(serialRecive);
          Serial.println(F("done!"));
          if(serialRecive=='s')
          {
            Serial.println();
            Serial.println(F("set the cocoon group!,no.1/3/5 is group 1,no.2/4/6 is group 2"));
            Serial.print(F("group="));
            while(1)
            {
              gNum = Serial.parseInt();
              if(gNum==1||gNum==2)
              {
                EEPROM.write(2,gNum);
                Serial.println(gNum);
                break;
              }
            }
          }
          break;
        }
      }
      break;
  }
//cocoonPlayer.cocoonPlay(1);//big cocoon
//small cocoon,group 1 is no.1&3&5 , group 2 is no.2&4&6. 
//cocoonPlayer.cocoonPlay(2,1);
//  cocoonPlayer.cocoonPlay(2,2);
//  keepTheSpkOn(7,23,30);
}

void serialEvent()
{
  serialRecive = Serial.read();
  //Serial.println(serialRecive);
  switch(serialRecive)
  {
    case 'd':case 'D': //debug switch
      debugStatus=debugStatus==true?false:true;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
      break;
    case 'i':case'I':
      status_Info();
      break;
    case 'a':case'A':
      lightModeSwitch(1);
      break;
    case 'b':case'B':
      lightModeSwitch(4);
      break;
    case 'p':case'P':
      myDFPlayer.stop();
      soundOneStatus=true;
      playerStatus=true;
      delay(10);
      soundPlay(1,20); // Cocoon big
      //soundPlay(1,23); //Cocoon small
      break;
    case 't':case 'T':
      myDFPlayer.stop();
      break;
    case 'l':case 'L':
      lightModeSwitch(2);
      break;
    case 'm':case 'M':
      EEPROM.update(1,'n');
      break;
    default:
      break;
  }
}

#include <Wire.h>
#include "Adafruit_NeoPixel.h"

#define PIN 2
#define NUM_LEDS 400 //big cocoon
//#define NUM_LEDS 150 //small cocoon
const int SLAVE_ADDRESS = 1;
char lightMode;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_BRG + NEO_KHZ800);

static int bright_level;

void setup() 
{  
  Wire.begin(SLAVE_ADDRESS);    // join I2C bus as a slave with address 1
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);
  led_Init();
  Serial.println("Received data:");
}

void loop() 
{
  switch(lightMode)
  {
    case 'b':
      fade_up();
      break;
    case 'c':
      fade_down();
      lightMode='a';
      break;
    case 'd':
      led_Init();
      break;
    default:
      fade_normalMode();
      break;
  }
//  if(lightMode=='a')
//  {
//    fade_normalMode(); 
//  }
//  if(lightMode=='b')
//  {
//    fade_up();
//  }
//  if(lightMode=='c')
//  {
//    fade_down();
//    lightMode='a';
//  }
//  if(lightMode=='d')
//  {
//    led_Init();
//  }
  Serial.println(lightMode);
}

void receiveEvent(int howMany)
{
  while (Wire.available()) 
  {
    // receive one byte from Master
    lightMode = Wire.read();
    //Serial.print(incomingByte);
  }
}

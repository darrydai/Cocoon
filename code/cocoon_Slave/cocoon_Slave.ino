#include <Wire.h>
#include "Adafruit_NeoPixel.h"

#define PIN 2
#define NUM_LEDS 100

const int SLAVE_ADDRESS = 1;
char lightMode = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_BRG + NEO_KHZ800);

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
  if(lightMode=='a')
  {
    fade_normalMode(); 
  }
  else if(lightMode=='b')
  {
    fade_up();
  }
  else if(lightMode=='c')
  {
    fade_down();
    lightMode='a';
  }
  else if(lightMode=='d')
  {
    led_Init();
  }
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

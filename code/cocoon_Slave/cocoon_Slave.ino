#include <Wire.h>
#include "Adafruit_NeoPixel.h"

#define PIN 2
#define NUM_LEDS 100
#define init_BRIGHTNESS 0
#define brightness

const int SLAVE_ADDRESS = 1;
char incomingByte = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_BRG + NEO_KHZ800);

void setup() {  
  Wire.begin(SLAVE_ADDRESS);    // join I2C bus as a slave with address 1
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);
  led_Init();
  Serial.println("Received data:");
}

void loop() 
{
  if(incomingByte=='a')
  {
    fade(); 
  }
  else if(incomingByte=='b')
  {
    fade_Playmode;
  }
  else if(incomingByte=='c')
  {
    led_Init();
  }
  Serial.println(incomingByte);
}

void receiveEvent(int howMany)
{
  while (Wire.available()) 
  {
    // receive one byte from Master
    incomingByte = Wire.read();
    //Serial.print(incomingByte);
  }
}

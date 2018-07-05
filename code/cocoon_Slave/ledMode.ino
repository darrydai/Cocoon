void fade_normalMode()
{
  volatile int bright_level;
  volatile int led_pos;
  for(bright_level=0;bright_level<=100;bright_level+=2)
  {
    for(int led_pos=0;led_pos<=NUM_LEDS;led_pos++)
    {
      strip.setPixelColor(led_pos, strip.Color(10,136,190));
    }
    strip.setBrightness(bright_level);
    strip.show();
    delay(50); 
  }
  for(bright_level=100;bright_level>=0;bright_level-=2)
  {
    for(int led_pos=0;led_pos<=NUM_LEDS;led_pos++)
    {
      strip.setPixelColor(led_pos, strip.Color(10,136,190));
    }
    strip.setBrightness(bright_level);
    strip.show();
    delay(50); 
  }
}

void fade_up()
{ 
  static int bright_level;
  volatile int led_pos;
  if(bright_level<1)
  {
    for(bright_level=0;bright_level<=100;bright_level+=2)
    {
      for(led_pos=0;led_pos<=NUM_LEDS;led_pos++)
      {
        strip.setPixelColor(led_pos, strip.Color(10,136,190));
      }
      strip.setBrightness(bright_level);
      strip.show();
      delay(50); 
    }
  }
}

void fade_down()
{ 
  volatile int bright_level;
  volatile int led_pos;
  for(bright_level=100;bright_level>=0;bright_level-=2)
  {
    for(int led_pos=0;led_pos<=NUM_LEDS;led_pos++)
    {
      strip.setPixelColor(led_pos, strip.Color(10,136,190));
    }
    strip.setBrightness(bright_level);
    strip.show();
    delay(50); 
  }
}

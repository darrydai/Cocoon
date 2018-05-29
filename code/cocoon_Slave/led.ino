void led_Init()
{
  for(int i=0;i<=NUM_LEDS;i++)
  {
    strip.setPixelColor(i, strip.Color(10,136,190));
  }
  strip.setBrightness(0);
  strip.begin();
  strip.show();
}

void fade()
{
  for(int x=0;x<=100;x+=5)
  {
    for(int i=0;i<=NUM_LEDS;i++)
    {
      strip.setPixelColor(i, strip.Color(10,136,190));
    }
    strip.setBrightness(x);
    strip.show();
    delay(110); 
  }
  for(int x=100;x>=0;x-=5)
  {
    for(int i=0;i<=NUM_LEDS;i++)
    {
      strip.setPixelColor(i, strip.Color(10,136,190));
    }
    strip.setBrightness(x);
    strip.show();
    delay(110); 
  }
}


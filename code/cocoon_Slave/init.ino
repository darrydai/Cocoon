void led_Init()
{
  for(int x=0;x<3;x++)
  {
    for(int i=0;i<=NUM_LEDS;i++)
    {
      strip.setPixelColor(i, strip.Color(0,0,0));
    }
    strip.setBrightness(0);
    strip.begin();
    strip.show();
  }
}

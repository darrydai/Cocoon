void rtc_Init()
{
  rtc.begin();
  delay(10);   // wait wire to stable
  if( !checki2cdevice( DS3231_ADDRESS ) )  
  { 
    Serial.println( "DS3231 RTC Module not found!" );   // 沒有 delay(10), 這裡輸出不了！
    while(1) delay(1);
  }

  if (rtc.lostPower()) 
  {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    DateTime timeupdate = DateTime( F( __DATE__ ), F( __TIME__ ) ) + TimeSpan( /*days*/0, /*hours*/0, /*minutes*/0, /*seconds*/20 );
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    rtc.adjust( timeupdate );
  }
}

bool checki2cdevice( uint8_t i2caddr ) 
{
    // 呼叫此函示之前, Wire 必須先初始化
    Wire.beginTransmission( i2caddr );
    if( Wire.endTransmission() == 0 ) return true;
    return false;
}


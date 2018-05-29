bool checki2cdevice( uint8_t i2caddr ) 
{
    // 呼叫此函示之前, Wire 必須先初始化
    Wire.beginTransmission( i2caddr );
    if( Wire.endTransmission() == 0 ) return true;
    return false;
}

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

void rtc_CheackFuntion()
{
    DateTime now = rtc.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

//    Serial.print(cheack_Time);
//    Serial.println();
    
    Serial.print(" since midnight 1/1/1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);
    Serial.println("d");
    
    // calculate a date which is 7 days and 30 seconds into the future
    DateTime future (now + TimeSpan(7,12,30,6));
    
    Serial.print(" now + 7d + 30s: ");
    Serial.print(future.year(), DEC);
    Serial.print('/');
    Serial.print(future.month(), DEC);
    Serial.print('/');
    Serial.print(future.day(), DEC);
    Serial.print(' ');
    Serial.print(future.hour(), DEC);
    Serial.print(':');
    Serial.print(future.minute(), DEC);
    Serial.print(':');
    Serial.print(future.second(), DEC);
    Serial.println();
 
    Serial.println();
    delay(1000);
}


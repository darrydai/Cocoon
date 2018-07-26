void lightModeSwitch(int mode)
{
  switch (mode)
  {
    case 1:
        ledTransmission('a');
        if(debugStatus==true)
        {
          Serial.println(F("light_On"));
        }
      break;
    case 2:
        ledTransmission('b');
        if(debugStatus==true)
        {
          Serial.println(F("fade_Up"));
        }
      break;
    case 3:
        ledTransmission('c');
        fadedown=true;
        if(debugStatus==true)
        {
          Serial.println(F("fade_Down"));
        }
      break;
    case 4:

        ledTransmission('d');
        if(debugStatus==true)
        {
          Serial.println(F("light_Off"));
        }
      break;
    default:
      break;
  }
}

void ledTransmission(char _lightMode)
{
  const int SLAVE_ADDRESS = 1;
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(_lightMode);
  Wire.endTransmission();
}

void light()
{
  if(currentTime_hour<18 && currentTime_hour>0)
  {
    lightModeSwitch(4);
    delay(100);
  }
  else
  {
    if(soundOneStatus==true)
    {
      if(fadedown==false)
      {
        lightModeSwitch(2);
      }
    }
    if(fadedown==true)
    {
      lightModeSwitch(1);
    }
    else
    {
      lightModeSwitch(3);
    }
  }
}


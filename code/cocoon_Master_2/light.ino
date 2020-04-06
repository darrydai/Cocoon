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
        //fadedown=true;
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
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(_lightMode);
  Wire.endTransmission();
}

void light()
{
  switch(soundOneStatus)
  {
    case true:
      lightModeSwitch(2);
      break;
    case false:
      switch(ledFadedown)
      {
        case false:
          lightModeSwitch(1);
          break;
        case true:
          lightModeSwitch(3);
          delay(200);
          ledFadedown=false;
          break;
      }
      break;
  }
}

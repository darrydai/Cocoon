void lightModeSwitch(int mode)
{
  switch (mode)
  {
    case 1:
//        lightMode='a';
//        Wire.beginTransmission(SLAVE_ADDRESS);
//        Wire.write(lightMode);
//        Wire.endTransmission();
        ledTransmission('a');
        if(debugStatus==true)
        {
          Serial.println(F("light_On"));
        }
      break;
    case 2:
//        lightMode='b';
//        Wire.beginTransmission(SLAVE_ADDRESS);
//        Wire.write(lightMode);
//        Wire.endTransmission();
        ledTransmission('b');
        if(debugStatus==true)
        {
          Serial.println(F("fade_Up"));
        }
      break;
    case 3:
//        lightMode='c';
//        Wire.beginTransmission(SLAVE_ADDRESS);
//        Wire.write(lightMode);
//        Wire.endTransmission();
        ledTransmission('c');
        fadedown=true;
        if(debugStatus==true)
        {
          Serial.println(F("fade_Down"));
        }
      break;
    case 4:
//        lightMode='d';
//        Wire.beginTransmission(SLAVE_ADDRESS);
//        Wire.write(lightMode);
//        Wire.endTransmission();
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



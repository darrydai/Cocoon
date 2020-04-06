void status_Info()
{
  Serial.println();
  Serial.print(F("cocoonType:"));
  Serial.write(EEPROM.read(1));
  if(type=='s')
  {
    Serial.print("  ");
    Serial.print(F("sCocoonGroup:"));
    Serial.println(gNum);
  }else{
    Serial.println();
  }
  Serial.print(F("playerStatus:"));
  Serial.println(playerStatus);
  Serial.print(F("soundOneStatus"));
  Serial.println(soundOneStatus);
  Serial.print(F("ledFadedown:"));
  Serial.println(ledFadedown);
}

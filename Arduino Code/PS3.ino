USB Usb;
PS3USB PS3(&Usb);

void PS3_init() {
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo,
  //Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.println(F("\r\nPS3 USB Library Started"));
}

void PS3_getValue() {
  Usb.Task();
  if (PS3.PS3Connected) {
    ps = PS3.getButtonClick(PS);  
    lhy = 127 - PS3.getAnalogHat(LeftHatY);
    l2 = PS3.getAnalogButton(L2);
    r2 = PS3.getAnalogButton(R2);
    rhy = 127 - PS3.getAnalogHat(RightHatY); // for fan
    rhx = 127 - PS3.getAnalogHat(RightHatX);
    sqr = PS3.getButtonClick(SQUARE);
    crs = PS3.getButtonClick(CROSS);
    cir = PS3.getButtonPress(CIRCLE);
    tri = PS3.getButtonClick(TRIANGLE);
    l1 = PS3.getButtonClick(L1);
    r1 = PS3.getButtonClick(R1);
    up = PS3.getButtonPress(UP);
    down = PS3.getButtonPress(DOWN);
    left = PS3.getButtonClick(LEFT);
    right = PS3.getButtonClick(RIGHT);
    srt = PS3.getButtonClick(START);

    // print values.
    //        Serial.print(lhy);
    //        Serial.print("\t");
    //        Serial.print(l2);
    //        Serial.print("\t");
    //        Serial.print(r2);
    //        Serial.print("\t");
    //        Serial.print(rhx);
    //        Serial.print("\t Slider part");
    //        Serial.println(rhy);
  }
}

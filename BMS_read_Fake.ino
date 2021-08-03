void readBMS_fake() { // Fake-Datenstrom zum Testen des Restprogramms
  int checksum=0;
  
  delay(300);
  if (dummy == 12)
  {
  checksum=1;
  dummy = 0;
  }
  else
  {
    checksum = 0;
  }
  dummy++;

//  checksum = 0;
  BMSMsg[57] = 0;
  if ( checksum == BMSMsg[57]) 
  {
    BMSok = true;
    
    // Batteryvoltage
    Batteryvoltage = 123;

    dummy_current = dummy_current -10;
    if (dummy_current < 0) {dummy_current = 200;}

    // Currentsensor 1
    Current1signHEX = 43;
    Current1 = dummy_current + 1;
    
    // Currentsensor 2
    Current2signHEX = 43;
    Current2 = dummy_current + 2;

    // Currentsensor 3
    Current3signHEX = 43;
    Current3 = dummy_current + 3;

    // Vmin 
    Vmin = 3.1;
    CellVminHEX = 1+CellNo;

    // Vmax 
    Vmax = 4.2;
    CellVmaxHEX = 3+CellNo;

    // Tmin 
    Tmin = CellNo*1.0;
    CellTminHEX = 2+CellNo;

    // Tmax 
    Tmax = 24.0;
    CellTmaxHEX = 4+CellNo;

    // Cell Infos
    
    CellNo++;
    if (CellNo > 35) {CellNo = 1;}
    NoOfAllCells = 35;
    CellVoltage = 3.0 + (CellNo/100.0);
    CellVolt[CellNo] = CellVoltage;
    CellTemp = CellNo;
    CellT[CellNo] = CellTemp;

    if (BMSstatus == 0b11111111) { BMSstatus = 0b00000000; } else  {BMSstatus = 0b11111111 ;}
    // Status evtl. decodieren! Siehe Doku S. 2
    AllowCharge    = BMSstatus & 0b00000001;     // Bit 0, Allow to charge - LSB of Status
    AllowDisCharge = BMSstatus & 0b00000010;     // Bit 1, Allow to discharge
    CommError      = BMSstatus & 0b00000100;     // Bit 2, Communication Error
    Exceed_Vmin    = BMSstatus & 0b00001000;     // Bit 3, Exceed V-MIN
    Exceed_Vmax    = BMSstatus & 0b00010000;     // Bit 4, Exceed V-MAX
    Exceed_Tmin    = BMSstatus & 0b00100000;     // Bit 5, Exceed T-MIN
    Exceed_Tmax    = BMSstatus & 0b01000000;     // Bit 6, Exceed T-MAX
    SOCnoCalib     = BMSstatus & 0b10000000;     // Bit 7, SOC not calibrated
   

    // Collected Energy
    CollectedEnergy = 1001;

    // Stored Energy
    StoredEnergy = 1002;

    // Consumed Energy
    ConsumedEnergy = 1003;
    
    // SOC
    socHEX = socHEX -5;
    if (socHEX < 1) {socHEX = 100;}
    
    // Total Stored Energy
    TotalStoredEnergy = 2001;

    // Total Consumed Energy
    TotalConsumedEnergy = 2002;

    // Device Time
    DeviceTimeMHEX = 9;
    DeviceTimeHHEX = 8;
    DeviceTimeH = DeviceTimeHHEX * 1;
    DeviceTimeM = DeviceTimeMHEX * 1;

    // Battery capacity
   BatteryCapacity = 120;

    // V-Min Setting
   VMinSetting = 2.8;

    // V-Max Setting
    VMaxSetting = 4.2;

    // V-Bypass Setting
   VBypassSetting = 4.1;
        
  }   // if ( checksum == BMSMsg[57])
   else
  {
    BMSok = false;
  }  // else if ( checksum == BMSMsg[57])

} // readBMS

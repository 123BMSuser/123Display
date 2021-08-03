void readBMS() { // Datenstrom auslesen und dekodieren
  int BytesGelesen = 0;
  int checksum = 0;
  int BMSbytes = 0;

  Serial1.begin(9600); // starte UART fuer BMS
  while (BMSbytes <= 57)  
  {
    if (Serial1.available())
    {
      BMSMsg[BMSbytes] = Serial1.read();
      BMSbytes++;
    }
  } // while
  Serial1.end(); // stoppe UART fuer BMS
 
  // Summiere checksum
  for (int count=0; count <= 56; count++)
  {
    checksum += BMSMsg[count];
  }
 
  checksum = checksum & 0xFF; // nur das low byte
  // Wenn checksum is ok go on 
  if (checksum == BMSMsg[57]) 
  {
    BMSok = true;
    
    // Batteryvoltage
    BatteryvoltageHEX = (BMSMsg[0]<<16) | (BMSMsg[1]<<8)| BMSMsg[2];
    Batteryvoltage = BatteryvoltageHEX * 0.005;

    // Currentsensor 1
    Current1signHEX = BMSMsg[3];
    Current1HEX = (BMSMsg[4]<<8)| BMSMsg[5];
    Current1 = Current1HEX * 0.125;
    
    // Currentsensor 2
    Current2signHEX = BMSMsg[6];
    Current2HEX = (BMSMsg[7]<<8)| BMSMsg[8];
    Current2 = Current2HEX * 0.125;

    // Currentsensor 3 - bei 1-Sensor Config (Laden & Entladen
    Current3signHEX = BMSMsg[9];
    Current3HEX = (BMSMsg[10]<<8)| BMSMsg[11];
    Current3 = Current3HEX * 0.125;

    // Vmin 
    VminHEX = (BMSMsg[12]<<8)| BMSMsg[13];
    Vmin = VminHEX * 0.005;
    CellVminHEX = BMSMsg[14];

    // Vmax 
    VmaxHEX = (BMSMsg[15]<<8)| BMSMsg[16];
    Vmax = VmaxHEX * 0.005;
    CellVmaxHEX = BMSMsg[17];

    // Tmin 
    TminHEX = (BMSMsg[18]<<8)| BMSMsg[19];
    CellTminHEX = BMSMsg[20];
//    Tmin = TminHEX * 1 - TempOffSet + TempCorr[CellTminHEX];
    Tmin = TminHEX * 1 - TempOffSet;

    // Tmax 
    TmaxHEX = (BMSMsg[21]<<8)| BMSMsg[22];
    CellTmaxHEX = BMSMsg[23];
//    Tmax = TmaxHEX * 1 - TempOffSet + TempCorr[CellTmaxHEX];
    Tmax = TmaxHEX * 1 - TempOffSet;

    // Cell Infos
    CellNo = BMSMsg[24];
    NoOfAllCells = BMSMsg[25];
    if (CellNo <= NoOfAllCells) {
      CellVoltageHEX = (BMSMsg[26]<<8)| BMSMsg[27];
      CellVoltage = CellVoltageHEX * 0.005;
      CellVolt[CellNo] = CellVoltage;
      CellTempHEX = (BMSMsg[28]<<8)| BMSMsg[29];
//      CellTemp = CellTempHEX * 1 - TempOffSet + TempCorr[CellNo];
      CellTemp = CellTempHEX * 1 - TempOffSet;
      CellT[CellNo] = CellTemp;
    } // if (CellNo <= NoOfAllCells)
    
    BMSstatus = BMSMsg[30];
    // Siehe Protokoll-Doku S. 2
    AllowCharge    = BMSstatus & 0b00000001;     // Bit 0, Allow to charge - LSB of Status
    AllowDisCharge = BMSstatus & 0b00000010;     // Bit 1, Allow to discharge
    CommError      = BMSstatus & 0b00000100;     // Bit 2, Communication Error
    Exceed_Vmin    = BMSstatus & 0b00001000;     // Bit 3, Exceed V-MIN
    Exceed_Vmax    = BMSstatus & 0b00010000;     // Bit 4, Exceed V-MAX
    Exceed_Tmin    = BMSstatus & 0b00100000;     // Bit 5, Exceed T-MIN
    Exceed_Tmax    = BMSstatus & 0b01000000;     // Bit 6, Exceed T-MAX
    SOCnoCalib     = BMSstatus & 0b10000000;     // Bit 7, SOC not calibrated

    // Collected Energy
    CollectedEnergyHEX = (BMSMsg[31]<<16)|(BMSMsg[32]<<8)| BMSMsg[33];
    CollectedEnergy = CollectedEnergyHEX * 1;

    // Stored Energy
    StoredEnergyHEX = (BMSMsg[34]<<16)|(BMSMsg[35]<<8)| BMSMsg[36];
    StoredEnergy = StoredEnergyHEX * 1;

    // Consumed Energy
    ConsumedEnergyHEX = (BMSMsg[37]<<16)|(BMSMsg[38]<<8)| BMSMsg[39];
    ConsumedEnergy = ConsumedEnergyHEX * 1;
    
    // SOC
    socHEX = BMSMsg[40];
    
    // Total Stored Energy
    TotalStoredEnergyHEX = (BMSMsg[41]<<16)|(BMSMsg[42]<<8)| BMSMsg[43];
    TotalStoredEnergy = TotalStoredEnergyHEX * 1;

    // Total Consumed Energy
    TotalConsumedEnergyHEX = (BMSMsg[44]<<16)|(BMSMsg[45]<<8)| BMSMsg[46];
    TotalConsumedEnergy = TotalConsumedEnergyHEX * 1;

    // Device Time
    DeviceTimeMHEX = BMSMsg[47];
    DeviceTimeHHEX = BMSMsg[48];
    DeviceTimeH = DeviceTimeHHEX * 1;
    DeviceTimeM = DeviceTimeMHEX * 1;

    // Battery capacity
    BatteryCapacityHEX = (BMSMsg[49]<<8)| BMSMsg[50];
    BatteryCapacity = BatteryCapacityHEX * 0.1;

    // V-Min Setting
    VMinSettingHEX = (BMSMsg[51]<<8)| BMSMsg[52];
    VMinSetting = VMinSettingHEX * 0.005;

    // V-Max Setting
    VMaxSettingHEX = (BMSMsg[53]<<8)| BMSMsg[54];
    VMaxSetting = VMaxSettingHEX * 0.005;

    // V-Bypass Setting
    VBypassSettingHEX = (BMSMsg[55]<<8)| BMSMsg[56];
    VBypassSetting = VBypassSettingHEX * 0.005;
        
  }   // if ( checksum == BMSMsg[57])
   else
  {
    BMSok = false;
  }  // else if ( checksum == BMSMsg[57])

} // readBMS

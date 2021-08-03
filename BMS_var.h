  bool BMSok = false;       // Datendeklarationen für den BMS-Datenstrom
  byte BMSMsg[60] = {};
  float TempOffSet = 273.0;
  //       Tempcorr Block#         1. 2.  3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35
  const float TempCorr[36] = { 0,  1, 1, -1, 0, 0, 2, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 2, 0, 1, 0, 0, 0, 1, 1};

  // Spannungsablagen: Siehe Textdatei "Spannungsabweichungen.txt"
  
  // Achtung! Im Programm "BMS_read" ist der Index um 1 kleiner als die
                            // hier gelistete Byte-Nummer!
  int BatteryvoltageHEX = 0;
  float Batteryvoltage = 0; // Byte 1,2,3 - 0,005V/bit

  char Current1signHEX = 0; // Byte 4 - Ascii +,-,X
  int Current1HEX = 0;      // Byte 5,6 - 0,125A/bit
  float Current1 = 0;

  char Current2signHEX = 0; // Byte 7 - Ascii +,-,X
  int Current2HEX = 0;      // Byte 8,9 - 0,125A/bit
  float Current2 = 0;

  char Current3signHEX = 0; // Byte 10 - Ascii +,-,X
  int Current3HEX = 0;      // Byte 11,12 - 0,125A/bit
  float Current3 = 0;
  
  int VminHEX = 0;          // Byte 13,14 - 0,005V/bit
  float Vmin = 0;
  int CellVminHEX = 0;      // Byte 15 - Cell# min
   
  int VmaxHEX = 0;          // Byte 16,17 - 0,005V/bit
  float Vmax = 0;
  int CellVmaxHEX = 0;      // Byte 18 - Cell# max

  int TminHEX = 0;          // Byte 19,20 - 1°C/bit offset 0x0114 = 0°C
  float Tmin = 0;
  int CellTminHEX = 0;      // Byte 21 - Cell# min T
   
  int TmaxHEX = 0;          // Byte 22,23 - 1°C/bit offset 0x0114 = 0°C
  float Tmax = 0;
  int CellTmaxHEX = 0;      // Byte 24 - Cell# max T

  byte CellNo = 0;          // Byte 25 - Info Cell#
  byte NoOfAllCells = 0;    // Byte 26 - Info Anzahl Zellen gem. DIP-Switches?
  int CellVoltageHEX = 0;   // Byte 27,28 - Info ZellSpannung von Cell#, 0,005V/bit 
  float CellVoltage = 3;   
  float CellVolt[42];       // BMS uebertraegt 40 Zell-Werte
  int CellTempHEX = 0;      // Byte 29,30 - Info ZellTemperatur 1°C/bit offset 0x0114 = 0°C
  float CellTemp = 0;
  float CellT[42];          // BMS uebertraegt 40 Zell-Werte
  
  byte BMSstatus = 1;          // Byte 31 - Info Status, siehe Doku
  bool AllowCharge = false;     // Bit 0, Allow to charge - LSB of Status
  bool AllowDisCharge = false; // Bit 1, Allow to discharge
  bool CommError = false;       // Bit 2, Communication Error
  bool Exceed_Vmin = false;     // Bit 3, Exceed V-MIN
  bool Exceed_Vmax = false;     // Bit 4, Exceed V-MAX
  bool Exceed_Tmin = false;     // Bit 5, Exceed T-MIN
  bool Exceed_Tmax = false;     // Bit 6, Exceed T-MAX
  bool SOCnoCalib = false;      // Bit 7, SOC not calibrated

  int CollectedEnergyHEX = 0; // Byte 32,33,34 - Today Energy Collected - Wh/bit
  float CollectedEnergy = 0;
  
  int StoredEnergyHEX = 0;    // Byte 35,36,37 - Energfy stored - Wh/bit
  float StoredEnergy = 0;

  int ConsumedEnergyHEX = 0;  // Byte 38,39,40 - Today Energy consumed - Wh/bit
  float ConsumedEnergy = 0;

  int socHEX = 100;             // Byte 41 SOC State of Charge - 1%/bit
  
  int TotalStoredEnergyHEX = 0; // Byte 42,43,44 - kWh/bit
  float TotalStoredEnergy = 0; 

  int TotalConsumedEnergyHEX = 0; // Byte 45,46,47 - kWh/bit
  float TotalConsumedEnergy = 0;

  int DeviceTimeMHEX = 0;         // Byte 48 - M/bit
  int DeviceTimeM = 0;
  int DeviceTimeHHEX = 0;         // Byte 49 - H/bit
  int DeviceTimeH = 0;

  int BatteryCapacityHEX = 0;     // Byte 50,51 - 0,1kWh/bit
  float BatteryCapacity = 0;

  int VMinSettingHEX = 0;     // Byte 52,53 - 0,005V/bit
  float VMinSetting = 0;
  
  int VMaxSettingHEX = 0;     // Byte 54,55 - 0,005V/bit
  float VMaxSetting = 0;
  
  int VBypassSettingHEX = 0;  // Byte 56,57 - Balancer-Spannung 0,005V/bit
  float VBypassSetting = 0;

//  int checksum=0;             //Byte 58 - Bytes 1 - 57 addieren und die unteren 8bit vergleichen

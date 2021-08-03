void seite_5() // Display BMS-Rohdaten
{
  int LiSpalte = 2;
  int LiSpace = 13;
  int ReSpalte = 230;
  int ReSpace = 14;
  int Zchnbreite = 6;
  int Zchnhoehe = 9;
  int LineSpace = Zchnhoehe * TextSize;
  int Zchnspace = TextSize * Zchnbreite;
 
  if (draw_frame)
  {
    tft.fillScreen(LCD_back);
    tft.setTextColor(TFT_BLACK, LCD_back);
    tft.setTextSize(TextSize);
    tft.setCursor(LiSpalte,0);
    tft.print("        ***** BMS RohDaten *****");
    tft.setCursor(LiSpalte,LineSpace);
    tft.print("B#1-3 Vbat:");
    tft.setCursor(LiSpalte,LineSpace*2);
    tft.print("B#4 I1 sig:");
    tft.setCursor(LiSpalte,LineSpace*3);
    tft.print("B#5,6  I1:");
    tft.setCursor(LiSpalte,LineSpace*4);
    tft.print("B#7 I2 sig:");
    tft.setCursor(LiSpalte,LineSpace*5);
    tft.print("B#8,9  I2:");
    tft.setCursor(LiSpalte,LineSpace*6);
    tft.print("B#10 I3 sig:");
    tft.setCursor(LiSpalte,LineSpace*7);
    tft.print("B#11,12 I3:");
    tft.setCursor(LiSpalte,LineSpace*8);
    tft.print("B#13,14 Vmin:");
    tft.setCursor(LiSpalte,LineSpace*9);
    tft.print("B#15 Vmin C#:");
    tft.setCursor(LiSpalte,LineSpace*10);
    tft.print("B#16,17 Vmax:");
    tft.setCursor(LiSpalte,LineSpace*11);
    tft.print("B#18 Vmax C#:");
    tft.setCursor(LiSpalte,LineSpace*12);
    tft.print("B#19,20 Tmin:");
    tft.setCursor(LiSpalte,LineSpace*13);
    tft.print("B#21 Tmin C#:");
    tft.setCursor(LiSpalte,LineSpace*14);
    tft.print("B#22,23 Tmax:");
    tft.setCursor(LiSpalte,LineSpace*15);
    tft.print("B#24 Tmax C#:");
    
    tft.setCursor(ReSpalte,LineSpace);
    tft.print("B#25 C# Info:");
    tft.setCursor(ReSpalte,LineSpace*2);
    tft.print("B#26 NrOfCel:");
    tft.setCursor(ReSpalte,LineSpace*3);
    tft.print("B#27,28 Vcel:");
    tft.setCursor(ReSpalte,LineSpace*4);
    tft.print("B#29,30 Tcel:");
    tft.setCursor(ReSpalte,LineSpace*5);
    tft.print("B#31 Status:");
    tft.setCursor(ReSpalte,LineSpace*6);
    tft.print("B#32-34TdColl:");
    tft.setCursor(ReSpalte,LineSpace*7);
    tft.print("B#35-37Stored:");
    tft.setCursor(ReSpalte,LineSpace*8);
    tft.print("B#38-40TdCons:");
    tft.setCursor(ReSpalte,LineSpace*9);
    tft.print("B#41      SOC:");
    tft.setCursor(ReSpalte,LineSpace*10);
    tft.print("B#42-44TotCol:");
    tft.setCursor(ReSpalte,LineSpace*11);
    tft.print("B#45-47TotCon:");
    tft.setCursor(ReSpalte,LineSpace*12);
    tft.print("B#48,49DevTim:");
    tft.setCursor(ReSpalte,LineSpace*13);
    tft.print("B#50,51BatCap:");
    tft.setCursor(ReSpalte,LineSpace*14);
    tft.print("B#52,53Vminst:");
    tft.setCursor(ReSpalte,LineSpace*15);
    tft.print("B#54,55Vmaxst:");
    tft.setCursor(ReSpalte,LineSpace*16);
    tft.print("B#56,57Vbypas:");
    tft.setCursor(ReSpalte,LineSpace*17);
    tft.print("B#58 Checksum:");
    draw_frame = false;
  } // if draw_frame

  if (BMSok)
  {
    // Batteryvoltage
    tft.setCursor(LiSpalte+(Zchnspace*(LiSpace-1)),LineSpace*1);
    tft.print(Batteryvoltage,1);

    // Currentsensor 1
    tft.setCursor(LiSpalte+(Zchnspace*LiSpace),LineSpace*2);
    tft.print(Current1signHEX);
    tft.setCursor(LiSpalte+(Zchnspace*(LiSpace-1)),LineSpace*3);
    tft.print(Current1,1);
    tft.print(" ");

    // Currentsensor 2
    tft.setCursor(LiSpalte+(Zchnspace*LiSpace),LineSpace*4);
    tft.print(Current2signHEX);
    tft.setCursor(LiSpalte+(Zchnspace*(LiSpace-1)),LineSpace*5);
    tft.print(Current2,1);
    tft.print(" ");

    // Currentsensor 3
    tft.setCursor(LiSpalte+(Zchnspace*LiSpace),LineSpace*6);
    tft.print(Current3signHEX);
    tft.setCursor(LiSpalte+(Zchnspace*(LiSpace-1)),LineSpace*7);
    tft.print(Current3,1);
    tft.print(" ");

    // Vmin 
    tft.setCursor(LiSpalte+(Zchnspace*LiSpace),LineSpace*9);
    tft.print(CellVminHEX);
    tft.print(" ");
    tft.setCursor(LiSpalte+(Zchnspace*LiSpace),LineSpace*8);
    tft.print(Vmin, 2);
    tft.print(" ");

    // Vmax 
    tft.setCursor(LiSpalte+(Zchnspace*LiSpace),LineSpace*11);
    tft.print(CellVmaxHEX);
    tft.print(" ");
    tft.setCursor(LiSpalte+(Zchnspace*LiSpace),LineSpace*10);
    tft.print(Vmax, 2);
    tft.print(" ");

    // Tmin 
    tft.setCursor(LiSpalte+(Zchnspace*LiSpace),LineSpace*13);
    tft.print(CellTminHEX);
    tft.print(" ");
    tft.setCursor(LiSpalte+(Zchnspace*LiSpace),LineSpace*12);
    tft.print(Tmin, 0);
    tft.print(" ");

    // Tmax 
    tft.setCursor(LiSpalte+(Zchnspace*13),LineSpace*15);
    tft.print(CellTmaxHEX);
    tft.print(" ");
    tft.setCursor(LiSpalte+(Zchnspace*13),LineSpace*14);
    tft.print(Tmax, 0);
    tft.print(" ");

    // Cell Infos
    if (CellNo <= NoOfAllCells)
    {
      tft.setCursor(ReSpalte+(Zchnspace*13),LineSpace);
      tft.print(CellNo);
      tft.print(" ");
      tft.setCursor(ReSpalte+(Zchnspace*13),LineSpace*2);
      tft.print(NoOfAllCells);
      tft.setCursor(ReSpalte+(Zchnspace*(ReSpace-1)),LineSpace*3);
      tft.print(CellVoltage, 2);
      tft.print(" ");
      tft.setCursor(ReSpalte+(Zchnspace*(ReSpace-1)),LineSpace*4);
      tft.print(CellTemp, 0);
      tft.print(" ");
    }

    // Status evtl. decodieren! Siehe Doku S. 2
    tft.setCursor(ReSpalte+(Zchnspace*12),LineSpace*5);
    tft.print("        ");
    tft.setCursor(ReSpalte+(Zchnspace*12),LineSpace*5);
    tft.print(BMSstatus, BIN);


    // Collected Energy
    tft.setCursor(ReSpalte+(Zchnspace*ReSpace),LineSpace*6);
    tft.print(CollectedEnergy,0);
    tft.print(" ");


    // Stored Energy
    tft.setCursor(ReSpalte+(Zchnspace*ReSpace),LineSpace*7);
    tft.print(StoredEnergy,0);
    tft.print(" ");


    // Consumed Energy
    tft.setCursor(ReSpalte+(Zchnspace*ReSpace),LineSpace*8);
    tft.print(ConsumedEnergy,0);
    tft.print(" ");
    
    // SOC
    tft.setCursor(ReSpalte+(Zchnspace*ReSpace),LineSpace*9);
    tft.print(socHEX, DEC);
    tft.print("% ");

    tft.setCursor(ReSpalte+(Zchnspace*ReSpace),LineSpace*10);
    tft.print(TotalStoredEnergy,0);
    tft.print(" ");

    tft.setCursor(ReSpalte+(Zchnspace*ReSpace),LineSpace*11);
    tft.print(TotalConsumedEnergy,0);
    tft.print(" ");

    // Device Time
    tft.setCursor(ReSpalte+(Zchnspace*ReSpace),LineSpace*12);
    if (DeviceTimeH < 10) {tft.print("0");}
    tft.print(DeviceTimeH);
    tft.print(":");
    if (DeviceTimeM < 10) {tft.print("0");}
    tft.print(DeviceTimeM);

    // Battery capacity
    tft.setCursor(ReSpalte+(Zchnspace*ReSpace),LineSpace*13);
    tft.print(BatteryCapacity,0);
    tft.print(" ");

    // V-Min Setting
    tft.setCursor(ReSpalte+(Zchnspace*ReSpace),LineSpace*14);
    tft.print(VMinSetting);

    // V-Max Setting
    tft.setCursor(ReSpalte+(Zchnspace*ReSpace),LineSpace*15);
    tft.print(VMaxSetting);

    // V-Bypass Setting
    tft.setCursor(ReSpalte+(Zchnspace*ReSpace),LineSpace*16);
    tft.print(VBypassSetting);

    // CheckSum
    tft.setCursor(ReSpalte+(Zchnspace*ReSpace),LineSpace*17);
    tft.print(BMSMsg[57],HEX);
    tft.print(" ");
    
    tft.fillCircle(310, 470, 5, LCD_back);  
        
  } // if BMSok
  
  
 } // seite_5

void seite_0() // Datendisplay komplett
{
  int LiSpalte = 10;
  int ReSpalte = 240;
  int Zchnbreite = 6;
  int Zchnhoehe = 9;
  int LineSpace = Zchnhoehe * TextSize;
  int Zchnspace = TextSize * Zchnbreite;
  int Top = 7;
  if (draw_frame)
  {
    tft.fillScreen(LCD_back);
    tft.setTextColor(TFT_BLACK, LCD_back);
    tft.setTextSize(TextSize);
    tft.setCursor(LiSpalte,Top);
    tft.print("Batteryvoltage: ");
    tft.setCursor(LiSpalte,Top+LineSpace*1);
    tft.print("Current: ");
    tft.setCursor(LiSpalte,Top+LineSpace*2);
    tft.print("Umin Blck#         Vmin: ");
    tft.setCursor(LiSpalte,Top+LineSpace*3);
    tft.print("Umax Blck#         Vmax: ");
    tft.setCursor(LiSpalte,Top+LineSpace*4);
    tft.print("Tmin Blck#         Tmin: ");
    tft.setCursor(LiSpalte,Top+LineSpace*5);
    tft.print("Tmax Blck#         Tmax: ");
    tft.setCursor(LiSpalte,Top+LineSpace*6);
    tft.print("Blck:    of ");
    tft.setCursor(LiSpalte,Top+LineSpace*7);
    tft.print("Blck Voltage:      Temp: ");
    tft.setCursor(LiSpalte,Top+LineSpace*8);
    tft.print("BMS  Status: ");
    tft.setCursor(LiSpalte,Top+LineSpace*9);
    tft.print("Collected Energy: ");
    tft.setCursor(LiSpalte,Top+LineSpace*10);
    tft.print("Stored Energy: ");
    tft.setCursor(LiSpalte,Top+LineSpace*11);
    tft.print("Consumed Energy: ");
    tft.setCursor(LiSpalte,Top+LineSpace*12);
    tft.print("SOC: ");
    tft.setCursor(LiSpalte,Top+LineSpace*13);
    tft.print("Device Time: ");
    tft.setCursor(LiSpalte,Top+LineSpace*14);
    tft.print("Battery capacity: ");
    tft.setCursor(LiSpalte,Top+LineSpace*15);
    tft.print("V-Min:      V-Max:      V-Bal: ");
    tft.setCursor(LiSpalte,Top+LineSpace*16);
    tft.print("Helligkeit:");
    draw_frame = false;
  } // if draw_frame

  if (BMSok)
  {
    // Batteryvoltage
    tft.setCursor(LiSpalte+(Zchnspace*16),Top);
    tft.print(Batteryvoltage);
    tft.print(" V  ");

    // Currentsensor 3
    tft.setCursor(LiSpalte+(Zchnspace*9),Top+LineSpace*1);
    tft.print(Current3signHEX);
    tft.print(Current3,1);
    tft.print(" A   ");

    // Vmin 
    tft.setCursor(LiSpalte+(Zchnspace*12),Top+LineSpace*2);
    tft.print(CellVminHEX);
    tft.print(" ");
    tft.setCursor(LiSpalte+(Zchnspace*25),Top+LineSpace*2);
    tft.print(Vmin, 2);
    tft.print(" V  ");

    // Vmax 
    tft.setCursor(LiSpalte+(Zchnspace*12),Top+LineSpace*3);
    tft.print(CellVmaxHEX);
    tft.print(" ");
    tft.setCursor(LiSpalte+(Zchnspace*25),Top+LineSpace*3);
    tft.print(Vmax, 2);
    tft.print(" V  ");

    // Tmin 
    tft.setCursor(LiSpalte+(Zchnspace*12),Top+LineSpace*4);
    tft.print(CellTminHEX);
    tft.print("  ");
    tft.setCursor(LiSpalte+(Zchnspace*25),Top+LineSpace*4);
    tft.print(Tmin + TempCorr[CellTminHEX], 0);
    tft.print(" C  ");

    // Tmax 
    tft.setCursor(LiSpalte+(Zchnspace*12),Top+LineSpace*5);
    tft.print(CellTmaxHEX);
    tft.print("  ");
    tft.setCursor(LiSpalte+(Zchnspace*25),Top+LineSpace*5);
    tft.print(Tmax + TempCorr[CellTmaxHEX], 0);
    tft.print(" C  ");

    // Cell Infos
    if (CellNo <= NoOfAllCells)
    {
      tft.setCursor(LiSpalte+(Zchnspace*6),Top+LineSpace*6);
      tft.print(CellNo);
      tft.print(" ");
      tft.setCursor(LiSpalte+(Zchnspace*12),Top+LineSpace*6);
      tft.print(NoOfAllCells);
      tft.setCursor(LiSpalte+(Zchnspace*13),Top+LineSpace*7);
      tft.print(CellVoltage, 2);
      tft.print("V ");
      tft.setCursor(LiSpalte+(Zchnspace*25),Top+LineSpace*7);
      tft.print(CellTemp + TempCorr[CellNo], 0);
      tft.print(" C  ");
    }

    // Status evtl. decodieren! Siehe Doku S. 2
    tft.setCursor(LiSpalte+(Zchnspace*19),Top+LineSpace*8);
    tft.print("        ");
    tft.setCursor(LiSpalte+(Zchnspace*19),Top+LineSpace*8);
    tft.print(BMSstatus, 2);


    // Collected Energy
    tft.setCursor(LiSpalte+(Zchnspace*19),Top+LineSpace*9);
    tft.print(CollectedEnergy,0);
    tft.print(" Wh  ");


    // Stored Energy
    tft.setCursor(LiSpalte+(Zchnspace*19),Top+LineSpace*10);
    tft.print(StoredEnergy,0);
    tft.print(" Wh  ");


    // Consumed Energy
    tft.setCursor(LiSpalte+(Zchnspace*19),Top+LineSpace*11);
    tft.print(ConsumedEnergy,0);
    tft.print(" Wh  ");

    
    // SOC
    tft.setCursor(LiSpalte+(Zchnspace*19),Top+LineSpace*12);
    tft.print(socHEX, DEC);
    tft.print(" %  ");

    // Device Time
    tft.setCursor(LiSpalte+(Zchnspace*19),Top+LineSpace*13);
    if (DeviceTimeH < 10) {tft.print("0");}
    tft.print(DeviceTimeH);
    tft.print(":");
    if (DeviceTimeM < 10) {tft.print("0");}
    tft.print(DeviceTimeM);

    // Battery capacity
    tft.setCursor(LiSpalte+(Zchnspace*19),Top+LineSpace*14);
    tft.print(BatteryCapacity,0);
    tft.print(" kWh ");
    

    // V-Min Setting
    tft.setCursor(LiSpalte+(Zchnspace*7),Top+LineSpace*15);
    tft.print(VMinSetting);


    // V-Max Setting
    tft.setCursor(LiSpalte+(Zchnspace*19),Top+LineSpace*15);
    tft.print(VMaxSetting);

    // V-Bypass Setting
    tft.setCursor(LiSpalte+(Zchnspace*31),Top+LineSpace*15);
    tft.print(VBypassSetting);

    // Helligkeit / LDR lesen
    tft.setCursor(LiSpalte+(Zchnspace*19),Top+LineSpace*16);
    tft.print(LDR);
    tft.print("  ");
    tft.fillCircle(310, 470, 5, LCD_back);  
        
  } // if BMSok
  
  
 } // seite_0

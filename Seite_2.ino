void seite_2() // Temperaturen und Status
{
  int LiSpalte = 10;
  int ReSpalte = 240;
  int Zchnbreite = 6;
  int Zchnhoehe = 9;
  int LineSpace = Zchnhoehe * TextSize;
  int Zchnspace = TextSize * Zchnbreite;
  int i;

  if (draw_frame)
  {
    tft.fillScreen(LCD_back);
    tft.setTextColor(TFT_BLACK, LCD_back);
    tft.setTextSize(TextSize);
    tft.setCursor(LiSpalte,3);
    tft.print("Temperaturen und Status:");
    tft.setCursor(LiSpalte,LineSpace*2);
    tft.print("Min Temp:");
    tft.setCursor(ReSpalte,LineSpace*2);
    tft.print("Block#:");
    tft.setCursor(LiSpalte,LineSpace*3);
    tft.print("Max Temp:");
    tft.setCursor(ReSpalte,LineSpace*3);
    tft.print("Block#:");
    tft.setCursor(LiSpalte,LineSpace*5);
    tft.print("Motor:");
    tft.setCursor(ReSpalte,LineSpace*5);
    tft.print("Wasser:");
    tft.setCursor(LiSpalte,LineSpace*7);
    tft.print("Aussen-Temperatur:");
    tft.setCursor(LiSpalte,LineSpace*9);
    tft.print("Status:");  
    tft.setCursor(ReSpalte,LineSpace*9);
    tft.print("Akku-Heizung:");

    draw_frame = false;
  } // if draw_frame    

  if (BMSok)
  {
    tft.setCursor(LiSpalte+(Zchnspace*10),LineSpace*2);
    tft.print(Tmin + TempCorr[CellTminHEX],0);
    tft.print("'C   ");
    tft.setCursor(ReSpalte+(Zchnspace*8),LineSpace*2);
    tft.print(CellTminHEX);
    tft.print(" ");
    tft.setCursor(LiSpalte+(Zchnspace*10),LineSpace*3);
    tft.print(Tmax + TempCorr[CellTmaxHEX],0);
    tft.print("'C   ");
    tft.setCursor(ReSpalte+(Zchnspace*8),LineSpace*3);
    tft.print(CellTmaxHEX);
    tft.print(" ");
    tft.setCursor(LiSpalte+(Zchnspace*7),LineSpace*5);
    tft.print(MotorTemp,1);
    tft.print("'C   ");
    tft.setCursor(ReSpalte+(Zchnspace*8),LineSpace*5);
    tft.print(WasserTemp,1);
    tft.print("'C   ");
    tft.setCursor(LiSpalte+(Zchnspace*19),LineSpace*7);
    tft.print(AussenTemp,1);
    tft.print("'C   ");
    tft.setCursor(ReSpalte+(Zchnspace*14),LineSpace*9);
    if (Heizen) {
      tft.setTextColor(TFT_RED,LCD_back);
      tft.print("Ein");
      tft.setTextColor(TFT_BLACK,LCD_back);
    }
    else {
      tft.setTextColor(TFT_BLUE,LCD_back);
      tft.print("Aus");
      tft.setTextColor(TFT_BLACK,LCD_back);
    }
    
    tft.setCursor(LiSpalte,LineSpace*10);
    if (AllowCharge)
      {
        tft.setTextColor(TFT_BLACK, TFT_GREEN);
        tft.print("OK: Laden               ");
      }
      else 
      {
        tft.setTextColor(LCD_back, TFT_RED);
        tft.print("Laden gesperrt          ");
      }

    tft.setCursor(LiSpalte,LineSpace*11);
    
    if (AllowDisCharge)
      {
        tft.setTextColor(TFT_BLACK, TFT_GREEN);
        tft.print("OK: Entladen            ");
      } 
      else 
      {
        tft.setTextColor(LCD_back, TFT_RED);
        tft.print("Entladen gesperrt       ");
      }
      
    tft.setCursor(LiSpalte,LineSpace*12);
    if (CommError)
    {
        tft.setTextColor(LCD_back, TFT_RED);
      tft.print("Fehler: Kommunikation   ");
      } 
      else 
      {
        tft.setTextColor(TFT_BLACK, TFT_GREEN);
        tft.print("OK: Kommunikation       ");
        }

    tft.setCursor(LiSpalte,LineSpace*13);
    if (Exceed_Vmin)
    {
      tft.setTextColor(LCD_back, TFT_RED);
      tft.print("Fehler: Unterspannung   ");
      } 
      else 
      {
      tft.setTextColor(TFT_BLACK, TFT_GREEN);
      tft.print("OK: > Umin              ");
      }

    tft.setCursor(LiSpalte,LineSpace*14);
    if (Exceed_Vmax)
    {
        tft.setTextColor(LCD_back, TFT_RED);
      tft.print("Fehler: Ueberspannung   ");
      } 
      else 
      {
        tft.setTextColor(TFT_BLACK, TFT_GREEN);
        tft.print("OK: < Umax              ");
        }

    tft.setCursor(LiSpalte,LineSpace*15);
    if (Exceed_Tmin)
    {
        tft.setTextColor(LCD_back, TFT_RED);
      tft.print("Fehler: Unter-Temperatur");
      } 
      else 
      {
        tft.setTextColor(TFT_BLACK, TFT_GREEN);
        tft.print("OK: > Tmin              ");
      }

    tft.setCursor(LiSpalte,LineSpace*16);
    if (Exceed_Tmax)
    {
        tft.setTextColor(LCD_back, TFT_RED);
      tft.print("Fehler: Uebertemperatur ");
      } 
      else 
      {
        tft.setTextColor(TFT_BLACK, TFT_GREEN);
        tft.print("OK: < Tmax              ");
      }

    tft.setCursor(LiSpalte,LineSpace*17);
    if (SOCnoCalib)
    {
        tft.setTextColor(LCD_back, TFT_RED);
        tft.print("SOC nicht kalibriert    ");
      } 
      else 
      {
        tft.setTextColor(TFT_BLACK, TFT_GREEN);
        tft.print("SOC kalibriert          ");
      }

  } // if BMSok
  
  tft.setTextColor(TFT_BLACK, LCD_back);

} // seite_2

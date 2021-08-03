void seite_1() // Grafische Hauptseite
  
{
  int LiSpalte = 130;
  int ReSpalte = 330;
  int Zchnbreite = 6;
  int Zchnhoehe = 9;
  int TextSize = 3;
  int LineSpace = TextSize * Zchnhoehe;
  int Zchnspace = TextSize * Zchnbreite;  
  int barcolor;
  float Vmit;
  tft.setTextColor(TFT_BLACK, LCD_back);
  tft.setTextSize(TextSize); 

  if (draw_frame)
  {
    tft.fillScreen(LCD_back);
    tft.drawFastVLine(10, 50, 260, TFT_BLACK);    
    tft.drawFastVLine(11, 50, 260, TFT_BLACK);    
    tft.drawFastVLine(12, 50, 260, TFT_BLACK);   
    tft.drawFastVLine(110, 50, 260, TFT_BLACK);    
    tft.drawFastVLine(111, 50, 260, TFT_BLACK);    
    tft.drawFastVLine(112, 50, 260, TFT_BLACK);   
    tft.drawFastHLine(10,308,103,TFT_BLACK);
    tft.drawFastHLine(10,309,103,TFT_BLACK);
    tft.drawFastHLine(10,310,103,TFT_BLACK);
    tft.drawFastHLine(10,50,30,TFT_BLACK);
    tft.drawFastHLine(10,51,30,TFT_BLACK);
    tft.drawFastHLine(10,52,30,TFT_BLACK);
    tft.drawFastHLine(80,50,30,TFT_BLACK);
    tft.drawFastHLine(80,51,30,TFT_BLACK);
    tft.drawFastHLine(80,52,30,TFT_BLACK);
    tft.drawFastVLine(37, 30, 20, TFT_BLACK);    
    tft.drawFastVLine(38, 30, 20, TFT_BLACK);    
    tft.drawFastVLine(39, 30, 20, TFT_BLACK);   
    tft.drawFastVLine(80, 30, 20, TFT_BLACK);    
    tft.drawFastVLine(81, 30, 20, TFT_BLACK);    
    tft.drawFastVLine(82, 30, 20, TFT_BLACK);   
    tft.drawFastHLine(40,30,40,TFT_BLACK);
    tft.drawFastHLine(40,31,40,TFT_BLACK);
    tft.drawFastHLine(40,32,40,TFT_BLACK);

    tft.setTextSize(TextSize+1); 
    tft.setCursor(LiSpalte, 20);
    tft.print("U:           ");
    tft.setCursor(LiSpalte, 60);
    tft.print("I:           ");
    tft.setTextSize(TextSize); 
    tft.setCursor(LiSpalte, LineSpace*4);
    tft.print("Umin:     ");
    tft.setCursor(ReSpalte, LineSpace*4);
    tft.print("Blk#:");
    tft.setCursor(LiSpalte, LineSpace*5);
    tft.print("Umax:     ");
    tft.setCursor(ReSpalte, LineSpace*5);
    tft.print("Blk#:");  
    tft.setCursor(LiSpalte, LineSpace*6);
    tft.print("Umit:     ");
    tft.setCursor(LiSpalte, LineSpace*7);
    tft.print("d-:     ");
    tft.setCursor(ReSpalte-30, LineSpace*7);
    tft.print("d+:    ");
    
    tft.setTextSize(2); 
    tft.setCursor(LiSpalte, 240);
    tft.print("Heute geladen:");
    tft.setCursor(LiSpalte, 280);
    tft.print("Batterie-Ladung:");
    draw_frame = false; 
  } // if (draw_frame)

  tft.setCursor(38,4);
  if (socHEX >= 50) { barcolor = TFT_GREEN;}
  if (socHEX < 50) { barcolor = TFT_YELLOW;}
  if (socHEX < 20) { barcolor = TFT_RED;}
  TextSize = 3;
  tft.setTextSize(TextSize);
  tft.print(socHEX, DEC);
  tft.print("% ");
  int height = 251*socHEX/100;
  tft.fillRect(15,55,93,251-height,LCD_back);
  tft.fillRect(15,55+251-height,93,height,barcolor);

  Zchnspace = TextSize * Zchnbreite;  
    tft.setTextSize(TextSize+1); 
    tft.setCursor(LiSpalte+(Zchnspace*3), 20);
    tft.print(Batteryvoltage,1);
    tft.print(" V  ");
    tft.setCursor(LiSpalte+(Zchnspace*3), 60);
    tft.print(Current3signHEX);
    tft.print(Current3,1);
    tft.print(" A  ");
        
  TextSize = 3;
  LineSpace = TextSize * Zchnhoehe;
  Zchnspace = TextSize * Zchnbreite;  
    tft.setTextSize(TextSize); 
    tft.setCursor(LiSpalte+(Zchnspace*5), LineSpace*4);
    tft.print(Vmin, 2);
    tft.print("V");
    tft.setCursor(ReSpalte+(Zchnspace*5), LineSpace*4);
    tft.print(CellVminHEX);
    tft.print(" ");
    tft.setCursor(LiSpalte+(Zchnspace*5), LineSpace*5);
    tft.print(Vmax, 2);
    tft.print("V");
    tft.setCursor(ReSpalte+(Zchnspace*5), LineSpace*5);
    tft.print(CellVmaxHEX);   
    tft.print(" ");
    tft.setCursor(LiSpalte+(Zchnspace*5), LineSpace*6);
    Vmit = Batteryvoltage / 35.0;
    tft.print(Vmit, 2);
    tft.print("V");
    tft.setCursor(LiSpalte+(Zchnspace*3), LineSpace*7);
    tft.print(Vmin-Vmit, 2);
    tft.print("V");
     tft.setCursor(ReSpalte+25, LineSpace*7);
    tft.print(Vmax-Vmit, 2);
    tft.print("V");
  
    tft.setTextSize(2); 
    tft.setCursor(LiSpalte, 260);
    tft.print(CollectedEnergy/1000.0,3);
    tft.print(" kWh     ");
    tft.setCursor(LiSpalte, 300);
    tft.print(StoredEnergy/1000.0,3);
    tft.print(" kWh     ");
  
} // seite_1

void seite_4() // Vorderer Kasten
{
  int LiSpalte = 10;
  int ReSpalte = 240;
  int Zchnbreite = 6;
  int Zchnhoehe = 9;
  int LineSpace = (Zchnhoehe + 5) * TextSize;
  int Zchnspace = TextSize * Zchnbreite;
  int i;

  if (draw_frame)
  {
    tft.fillScreen(LCD_back);
    tft.setTextColor(TFT_BLACK, LCD_back);
    tft.setTextSize(TextSize+1);
    tft.setCursor(LiSpalte,3);
    tft.print("Vorderer Kasten");
    tft.setTextSize(TextSize); 
    tft.setCursor(LiSpalte+(Zchnspace*25),3);
    tft.print("akt. Block:");  
    for ( i=21; i <= 28; i++){
    tft.setCursor(LiSpalte,LineSpace*(i-19));
    tft.print("#");
    tft.print(i);
    tft.print(":");
    }
  
    for ( i=29; i <= 35; i++){
    tft.setCursor(ReSpalte,LineSpace*(i-27));
    tft.print("#");
    tft.print(i);
    tft.print(":");
    }
    draw_frame = false;
  } // if draw_frame    

  if (BMSok)
  {
    tft.setCursor(ReSpalte+(Zchnspace*17),3);
    tft.print(CellNo);
    tft.print(" ");
    for ( i=21; i <= 28; i++){
    tft.setCursor(LiSpalte+(Zchnspace*4),LineSpace*(i-19));
    tft.print(CellVolt[i],2);
    tft.print("V  ");
    tft.print(CellT[i] + TempCorr[i],0);
    tft.print("'C   ");
    }
  } // if BMSok

       
  if (fake)
  {
   readBMS_fake();
  }
  else
  {
  readBMS();
  }
  
  if (BMSok)
  {
    tft.setCursor(ReSpalte+(Zchnspace*17),3);
    tft.print(CellNo);
    tft.print(" ");
    for ( i=29; i <= 35; i++){
    tft.setCursor(ReSpalte+(Zchnspace*4),LineSpace*(i-27));
    tft.print(CellVolt[i],2);
    tft.print("V  ");
    tft.print(CellT[i] + TempCorr[i],0);
    tft.print("'C   ");
    }
  } // if BMSok

} // seite_3

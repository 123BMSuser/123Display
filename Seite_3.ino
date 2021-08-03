void seite_3() // Hinterer Kasten
{
  int LiSpalte = 10;
  int ReSpalte = 250;
  int Zchnbreite = 6;
  int Zchnhoehe = 9;
  int LineSpace = (Zchnhoehe + 3) * TextSize;
  int Zchnspace = TextSize * Zchnbreite;
  int i;

  if (draw_frame)
  {
    tft.fillScreen(LCD_back);
    tft.setTextColor(TFT_BLACK, LCD_back);
    tft.setTextSize(TextSize+1);
    tft.setCursor(LiSpalte,3);
    tft.print("Hinterer Kasten");
    tft.setTextSize(TextSize);
    tft.setCursor(LiSpalte+(Zchnspace*25),3);
    tft.print("akt. Block:");  
 
    for ( i=1; i <= 10; i++){
    tft.setCursor(LiSpalte,LineSpace*(i+1));
    tft.print("#");
    if (i<10){tft.print("0");}
    tft.print(i);
    tft.print(":");
    }
    for ( i=11; i <= 20; i++){
    tft.setCursor(ReSpalte,LineSpace*(i-9));
    tft.print("#");
    tft.print(i);
    tft.print(":");
    }
    draw_frame = false;
  } // if draw_frame    

  if (BMSok)
  {
    tft.setCursor(ReSpalte+(Zchnspace*16),3);
    tft.print(CellNo);
    tft.print(" ");
    for ( i=1; i <= 10; i++){
    tft.setCursor(LiSpalte+(Zchnspace*4),LineSpace*(i+1));
    tft.print(CellVolt[i],2);
    tft.print("V  ");
    tft.print(CellT[i] + TempCorr[i],0);
    tft.print("'C  ");
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
    tft.setCursor(ReSpalte+(Zchnspace*16),3);
    tft.print(CellNo);
    tft.print(" ");
    for ( i=11; i <= 20; i++){
    tft.setCursor(ReSpalte+(Zchnspace*4),LineSpace*(i-9));
    tft.print(CellVolt[i],2);
    tft.print("V  ");
    tft.print(CellT[i] + TempCorr[i],0);
    tft.print("'C  ");
    }
  } // if BMSok
  
} // seite_4

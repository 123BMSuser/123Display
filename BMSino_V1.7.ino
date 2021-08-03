/*
 * Monitor für das 123\smartbms von 123electric.de
 * Daten werden von der EXT-Out Schnittstelle über Optokoppler getrennt empfangen,
 * decodiert und auf einem TFT Display angezeigt.
 * TFT ID = 0x6814
 * mit Touch integration
 * V 1.7 - 02.06.2021 - Th. Meier
 * Integration Schaltausgang Heizrelais
 * Temperaturkorrektur & geprueft
 * 
 * Block  7: -30mV
 * Block 24: -40mV
 */

// LCD
  #include <Adafruit_GFX.h>  //https://github.com/adafruit/Adafruit-GFX-Library
  #include <MCUFRIEND_kbv.h> //https://github.com/prenticedavid/MCUFRIEND_kbv
  MCUFRIEND_kbv tft;
  const int XP=6,XM=A2,YP=A1,YM=7; //320x480 ID=0x6814

// Touchscreen
  #include <TouchScreen.h>
  TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
  TSPoint tp;
  #define MINPRESSURE 100
  int akttp; // aktueller Touchpadwert
 
  #include "BMS_var.h"
  #include <eHaJo_LM75.h>
  EHAJO_LM75 tempsensor;

  bool fake = false;          // Steuerung des ReadBMS Aufrufs
  int dummy = 0;             // Fuer BMS_read_Fake
  float dummy_current = 200; // Fuer BMS_read_Fake
  
  bool Heizen = false;
  const byte Port_Heizrelais = 25; // Pin-Nr. des Mega2560, Log.H für angezogenes Relais = Heizen
  float Temp_Heiz_ein = 10.0;
  float Temp_Heiz_aus = 15.0;
  
  int TextSize = 2;
  
  int LCD_back = TFT_WHITE;
  int LCD_bright = LCD_back;
  int LCD_dim = TFT_DARKGREY;
  
  int page = 1; // Start-Screen
  const int page_max = 5;
  
  int LDR_dim = 500; // Schwelle für gedimmtes Display
  int LDR_old = 500;
  int LDR = 0;

  float MotorTemp = 24.1;  // LM75 Temperaturmessung
  float WasserTemp = 22.2;
  float AussenTemp = 16.3;
  
  bool draw_frame = true; // Kompletten Bildschirm neu zeichnen

void setup() 
{
  Wire.begin();       // start LM75 comm @ PIN20 (SDA) PIN21(SCL)
  tft.begin(0x6814);  // Mein TFT Display von modulink.de
  tft.setRotation(1); //Landscape, USB links
  tft.fillScreen(LCD_back);
  tft.setTextColor(TFT_BLACK, LCD_back);
  tft.setTextSize(TextSize);
  pinMode(Port_Heizrelais, OUTPUT); // sets the digital pin for Heiz_Relais as output
  digitalWrite(Port_Heizrelais, LOW); 
} // setup

void loop() 
{
  // Helligkeitssteuerung Tag <-> Nacht mit Hysterese +-20
      LDR = analogRead(10);
      if ( ((LDR >= LDR_dim+20) && (LDR_old < LDR_dim+20)) || ( (LDR < LDR_dim-20) && (LDR_old >= LDR_dim-20)))
        {
        draw_frame = true;           
       if (LDR < LDR_dim-20)
           {
           LCD_back = LCD_dim;
           }
       if (LDR > LDR_dim+20)
           {
           LCD_back = LCD_bright;
           }
        LDR_old = LDR;
        } // if LDR ...
       
  if (fake)
    {
     readBMS_fake(); // zum Testen
    }
   else
    {
     readBMS(); // "echtes Auslesen"
    }
  
   /* Seitenwahl mit Touchpad
   *  Rechts: tp.y < 350
   *  mitte: tp.y > 400 < 700
   *  links: tp.y > 750
   */
   
    tp = ts.getPoint();
    pinMode(XM, OUTPUT); // switch back for TFT access
    pinMode(YP, OUTPUT); // (shared pins)
    
    if (tp.z > MINPRESSURE) 
    {
        akttp = tp.y;
        if (akttp > 750) // bis ca. 960 @ max. links
           {
             if (page > 0)
             {
               page--;
             } // if (page > 0)
             else
             {
               page = page_max;
             } // if (page > 0)
           draw_frame = true;
           } // if (akttp > 750)
           
       if (akttp < 350) // bis ca. 180 @ max. rechts
       {
         if (page < page_max)
         {
          page++;
         } // if (page < page_max)
         else
         {
          page = 0;
         } // if (page < page_max)
       draw_frame = true;
       } // if (akttp < 350)
       
       if (akttp > 400 && akttp < 700)
           {
             page = 1;
             draw_frame = true;
           } 
    } // if > pressure (Seitenwahl)
    
  if (BMSok == false)
  {
    tft.fillCircle(466, 306, 10, TFT_RED);  // Signalisiere Checksum-Error
  } // if (BMSok == false)
  else
  {
    if (page == 0){seite_0();}
    if (page == 1){seite_1();}
    if (page == 2){seite_2();}
    if (page == 3){seite_3();}
    if (page == 4){seite_4();}
    if (page == 5){seite_5();}
    tft.fillCircle(466, 306, 10, LCD_back);  // reset Signalisiere Checksum-Error
  } // else if (BMSok == false)
  
// Temperaturen lesen
  tempsensor.setAddress(1,0,0);
  AussenTemp = tempsensor.getTemp(); // (Nr 1)
  tempsensor.setAddress(0,1,0);
  MotorTemp = tempsensor.getTemp(); // (Nr 2)
  tempsensor.setAddress(1,1,0);
  WasserTemp = tempsensor.getTemp(); // (Nr 3)

// Steuerung Akkuheizung
  if (Tmin < Temp_Heiz_ein && !Heizen) { Heizen = true; }
  if (Tmin > Temp_Heiz_aus && Heizen) { Heizen = false; }
  digitalWrite(Port_Heizrelais, Heizen);
}  // loop()

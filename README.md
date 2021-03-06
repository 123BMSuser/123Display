# 123Display
Arduino based display of data coming from [123smartBMS](https://123electric.eu/).

Hardware:
- Arduino mega 2560 R3
- 3.5" LCD display module with touch screen
- LDR (Light Dependent Resistor)
- Optocoupler SFH 611
- some resistors
- 5V and 3.3V switching regulator R-78B5.0-1.5 and R-78B3.3-1.5

Implementation for my electric car configuration:
Three LiIon pouch cells parallel connected are one block. 
35 blocks are serially connected.
20 blocks are stored in the back battery box.
15 blocks are in the front box.

Screens are choosen by touching the screen in the left or right quarter.
Thouching the middle area leads to main screen. 

**Main Screen:**

<img src="/Photos/Scr_1_main.jpg" width="500" alt="Main"/>

**Data overview:**

<img src="/Photos/Scr_0_data.jpg" width="500" alt="Main"/>

**Satus and temperatures:**

<img src="/Photos/Scr_2_Stat.jpg" width="500" alt="Main"/>

**Back battery box:**

<img src="/Photos/Scr_3_hk.jpg" width="500" alt="Main"/>

**Front battery box:**

<img src="/Photos/Scr_4_vk.jpg" width="500" alt="Main"/>

**BMS raw data:**

<img src="/Photos/Scr_5_raw.jpg" width="500" alt="Main"/>

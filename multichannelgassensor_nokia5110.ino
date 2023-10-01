#include<Multichannel_Gas_GMXXX.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
GAS_GMXXX<TwoWire> gas;
// Declare LCD object for software SPI
// Adafruit_PCD8544(CLK,DIN,D/C,CE,RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(14, 27, 26, 25, 33);

void setup()   {
  Serial.begin(115200);
  gas.begin(Wire, 0x08);

  //Initialize Display
  display.begin();

  // you can change the contrast around to adapt the display for the best viewing!
  display.setContrast(57);

  
}

void loop() {
  float NO2 = gas.measure_NO2();
  float C2H5OH = gas.measure_C2H5OH();
  float VOC = gas.measure_VOC();
  float CO = gas.measure_CO();

  Serial.print("NO2      :");
  Serial.println(NO2);
  Serial.print("C2H5OH   :");
  Serial.println(C2H5OH);
  Serial.print("VOC      :");
  Serial.println(VOC);
  Serial.print("CO       :");
  Serial.println(CO);
  Serial.println("==========================");
    delay(2000);

 //display NO2
  display.clearDisplay();
  display.setCursor(0, 0); 
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.println("NO2 :");
  display.setCursor(0, 20); 
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.print(NO2);
  display.display();
  delay(2000);

  
//display C2H5OH
  display.clearDisplay();
  display.setCursor(0, 0); 
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.println("C2H5OH :");
  display.setCursor(0, 20); 
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.print(C2H5OH);
  display.display();
  delay(2000);

//display VOC
  display.clearDisplay();
  display.setCursor(0, 0); 
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.println("VOC :");
  display.setCursor(0, 20); 
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.print(VOC);
  display.display();
  delay(2000);

//display CO
  display.clearDisplay();
  display.setCursor(0, 0); 
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.println("CO :");
  display.setCursor(0, 20); 
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.print(CO);
  display.display();
  delay(2000);
 
}

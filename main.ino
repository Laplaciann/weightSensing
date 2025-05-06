#include "HX711.h"
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
TinyGPSPlus gps;
SoftwareSerial mygps(10,11);
int x=1;
#define DOUT_PIN  6   
#define CLK_PIN   7   
const int sim900a_rx = 8; 
const int sim900a_tx = 9;
HX711 scale;


const float cal = 100; 
SoftwareSerial gsm(sim900a_rx, sim900a_tx);
void setup() {
  Serial.begin(9600);
  mygps.begin(9600);
  Serial.println("GPS TESTING");
   gsm.begin(9600);
   
   gsm.println("AT");
   delay(1000);
   gsm.println("AT+CMGF=1");
   delay(1000);
   scale.begin(DOUT_PIN, CLK_PIN);
   scale.set_scale(cal); 
}

void loop() {
  
   float weight = scale.get_units(10); 
   float final_weight = weight*0.2425 +1328.4726;
  
   Serial.println(final_weight, 25); 
   if(final_weight<500&&x==1)
   {
      while (mygps.available() > 0){
    gps.encode(mygps.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print("Longitude= "); 
      Serial.println(gps.location.lng(), 6);
      }
       
    }
      gsm.println("AT+CMGS=\"+919755092956\""); 
      delay(2000);
      gsm.print("LPG level is low. Kindly contact the operator");
      delay(2000);
      gsm.write((char)26); 
      x=2;
   }
   if(final_weight>500)
   {
      x=1;
   }

   delay(500); 
}

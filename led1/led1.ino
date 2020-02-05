#include "Adafruit_NeoPixel.h"
#include <EEPROM.h>

#define LED_COUNT 30

#define LED_PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
 
void setup()
{
    strip.begin();
    pinMode(3,OUTPUT);
    pinMode(4,INPUT);
    Serial.begin(9600);
}
void rainbow(){
   for (int r= 255; r>=0; r--){
   for (int i = 0; i < LED_COUNT; i++)
  {
    strip.setPixelColor(i, strip.Color(r,255-r, 0)); 
    
  }
  if(digitalRead(4)>0){ break;}
  strip.show();
  delay(10);
  }
  
 for (int g= 255; g>=0; g--){
   for (int i = 0; i < LED_COUNT; i++)
  {
    strip.setPixelColor(i, strip.Color(0,g, 255-g)); 
  }
  if(digitalRead(4)>0){ break;}
  strip.show();
  delay(10);
  } 
  
  for (int b= 255; b>=0; b--){
  for (int i = 0; i < LED_COUNT; i++)
  {
    strip.setPixelColor(i, strip.Color(255-b,0, b)); 
  }
  if(digitalRead(4)>0){ break;}
  strip.show();
 delay(10);
  }
  } 
void colour(int col){
  int r,g,b;
  switch(col){
    case 0:
      r=0;
      g=0;
      b=0;
    break;  
    case 1:
      r=255;
      g=0;
      b=0;
    break;
    case 2:
      r=255;
      g=255;
      b=0;
    break;
    case 3:
      r=0;
      g=255;
      b=0;
    break;
    case 4:
      r=0;
      g=255;
      b=255;
    break;
    case 5 :
      r=0;
      g=0;
      b=255;
    break; 
    case 6 : 
      r=255;
      g=255;
      b=255;
    break;
    }
  
  for (int i = 0; i < LED_COUNT; i++)
  {
    strip.setPixelColor(i, strip.Color(r,g, b)); 
  }

  strip.show();
  }
int i ; 
void loop()
{
  i=EEPROM.read(0);
  digitalWrite(3,HIGH);
  if(digitalRead(4)>0){
    i+=1;
    delay(1000);
    }
  
  if(i>7){i=0;}
  EEPROM.write(0,i);
  if(i==7){
    rainbow();
    }
  else{
    colour(i);
    } 

}

#include <Adafruit_NeoPixel.h>  //Library to simplify interacting with the LED strand
#ifdef __AVR__
#include <avr/power.h>   //Includes the library for power reduction registers if your chip supports them. 
#endif                   //More info: http://www.nongnu.org/avr-libc/user-manual/group__avr__power.htlm

//Constants (change these as necessary)
#define LED_PIN    5  //Pin for the pixel strand. Does not have to be analog.
#define LED_TOTAL 72  //Change this to the number of LEDs in your strand.

//////////<Globals>
//  These values either need to be remembered from the last pass of loop() or 
//  need to be accessed by several functions in one pass, so they need to be global.

Adafruit_NeoPixel strand = Adafruit_NeoPixel(LED_TOTAL, LED_PIN, NEO_GRB + NEO_KHZ800);  //LED strand objetc

void setup()
{
  strand.begin(); //Initialize the LED strand object.
  strand.show();  //Show a blank strand, just to get the LED's ready for use.
  Serial.begin(115200);  
}

void loop()
{
  for (int y=0; y<4; y++)
  {
    for (int x=0; x<72; x=x+9)
    {
      // Turn Off the LED's we truned on last time
      if (x==0)
      {
        for (int z=63; z<72; z++)
        {
          strand.setPixelColor(z, strand.Color(0,0,0));
          Serial.print("Unsetting Y=");
          Serial.print(y);
          Serial.print(" X=");
          Serial.print(x);
          Serial.print(" Z=");
          Serial.println(z);
        }
      } else {
        for (int z=x-9; z<x; z++)
        {
          strand.setPixelColor(z, strand.Color(0,0,0));
          Serial.print("Unsetting Y=");
          Serial.print(y);
          Serial.print(" X=");
          Serial.print(x);
          Serial.print(" Z=");
          Serial.println(z);
        }
      }

      // Turn on the next LED's
      for (int z=x; z<x+9; z++)
      {
        if (y==0) { strand.setPixelColor(z, strand.Color(255,0,0)); }
        if (y==1) { strand.setPixelColor(z, strand.Color(0,255,0)); }
        if (y==2) { strand.setPixelColor(z, strand.Color(0,0,255)); }
        if (y==3) { strand.setPixelColor(z, strand.Color(255,255,255)); }
        Serial.print("Setting   Y=");
        Serial.print(y);
        Serial.print(" X=");
        Serial.print(x);
        Serial.print(" Z=");
        Serial.println(z);
      }
      strand.show();
      delay(3000);
    }
    delay(3000);
  }
}

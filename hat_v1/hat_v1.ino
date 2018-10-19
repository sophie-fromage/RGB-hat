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
  Serial.begin(9600);  
}


void loop()
{
  for (int x=0; x<72; x++)
  {
    Serial.println(x);
    strand.setPixelColor(x, strand.Color(255,255,255));
    if(x==0) { strand.setPixelColor(71, strand.Color(0,0,0)); }
    else { strand.setPixelColor(x-1, strand.Color(0,0,0)); }
    strand.show();
    delay(200);
  }
}

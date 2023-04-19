#include "FastLED.h"

#define NUM_LEDS_PER_STRIP 5 //Use 5 LEDs in the Neopixel strips
#define DELAY_INTERVAL 150 //Delay in animation

CRGB redLeds[NUM_LEDS_PER_STRIP]; //CRGB array for red
CRGB greenLeds[NUM_LEDS_PER_STRIP]; //CRGB array for green
CRGB blueLeds[NUM_LEDS_PER_STRIP]; //CRGB array for blue


int firstKeyPin = 2; //Pin for red button
int secondKeyPin = 3; //Pin for green button
int thirdKeyPin = 4; //Pin for blue button


void setup() {
  FastLED.addLeds<NEOPIXEL, 8>(redLeds, NUM_LEDS_PER_STRIP); //Pin for 1st Neopixel strip
  FastLED.addLeds<NEOPIXEL, 9>(greenLeds, NUM_LEDS_PER_STRIP); //Pin for 2nd Neopixel strip
  FastLED.addLeds<NEOPIXEL, 10>(blueLeds, NUM_LEDS_PER_STRIP); //Pin for 3rd Neopixel strip

  pinMode(firstKeyPin, INPUT_PULLUP);
  pinMode(secondKeyPin, INPUT_PULLUP);
  pinMode(thirdKeyPin, INPUT_PULLUP);
} 

void loop() {
  if (digitalRead(firstKeyPin) == LOW) { //red animated Neopixel strip light up when red button is pressed
    for (int pixel = 0; pixel < NUM_LEDS_PER_STRIP; pixel++) { //for each pixel
      redLeds[pixel] = CRGB::Red; //set color to red
      FastLED.show(); //send the updated pixel colors to the NeoPixel hardware.
      delay(DELAY_INTERVAL); //pause between each pixel
    }
  }
  if (digitalRead(secondKeyPin) == LOW) { //green animated Neopixel strip when green button is pressed
    for (int pixel = 0; pixel < NUM_LEDS_PER_STRIP; pixel++) { //for each pixel
      greenLeds[pixel] = CRGB::Green; //set color to green
      FastLED.show(); //send the updated pixel colors to the NeoPixel hardware.
      delay(DELAY_INTERVAL); //pause between each pixel
    }
  }
  if (digitalRead(thirdKeyPin) == LOW) { //blue animted Neopixel strip when blue button is pressed
    for (int pixel = 0; pixel < NUM_LEDS_PER_STRIP; pixel++) { //for each pixel
      blueLeds[pixel] = CRGB::Blue; //set color to blue
      FastLED.show(); //send the updated pixel colors to the NeoPixel hardware.
      delay(DELAY_INTERVAL); //pause between each pixel
    }
  }
  else { //if no button is pressed, then don't light any strip up
    for (int pixel = 0; pixel < NUM_LEDS_PER_STRIP; pixel++) { //for each pixel
      redLeds[pixel] = CRGB::Black; //all set to black, since Neopixel doesn't have black, nothing will show
      greenLeds[pixel] = CRGB::Black;
      blueLeds[pixel] = CRGB::Black;
      FastLED.show();   // send the updated pixel colors to the NeoPixel hardware.
    }
  }
}


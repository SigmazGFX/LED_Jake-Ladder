#include "FastLED.h"
#include <PCM.h>

#define NUM_LEDS 12 // How many leds in your strip?
#define DATA_PIN 7 //  Which pin are we they connected?
#define LED_TYPE WS2812 //  LED Type?
CRGB leds[NUM_LEDS];
long randNumber;
const unsigned char sample[] PROGMEM = {
  87, 96, 101, 85, 114, 83, 110, 94, 89, 116, 94, 121, 112, 136, 132, 150, 154, 150, 168, 168, 170, 175, 179, 190, 161, 166, 159, 132, 136, 116, 132, 105, 121, 141, 112, 154, 119, 157, 134, 125, 150, 107, 150, 114, 128, 132, 128, 125, 112, 134, 103, 94, 107, 94, 141, 92, 152, 175, 89, 177, 87, 121, 136, 60, 152, 83, 98, 130, 71, 121, 101, 92, 114, 89, 92, 114, 83, 110, 119, 83, 161, 101, 148, 161, 125, 181, 154, 159, 197, 148, 177, 190, 141, 186, 134, 132, 141, 98, 128, 103, 92, 141, 121, 125, 152, 139, 159, 121, 145, 134, 130, 121, 139, 121, 130, 125, 101, 132, 74, 112, 123, 107, 132, 159, 114, 154, 105, 110, 123, 87, 119, 94, 101, 110, 89, 92, 101, 87, 92, 105, 85, 114, 94, 94, 123, 80, 125, 107, 110, 145, 125, 163, 148, 157, 195, 161, 175, 195, 166, 177, 159, 145, 139, 121, 134, 114, 103, 134, 123, 141, 136, 141, 172, 121, 148, 141, 128, 143, 116, 141, 121, 139, 107, 125, 94, 116, 89, 139, 114, 154, 163, 112, 177, 78, 143, 87, 87, 121, 65, 114, 96, 92, 107, 101, 92, 116, 92, 119, 101, 101, 128, 89, 123, 110, 114, 136, 130, 154, 154, 150, 175, 181, 157, 199, 166, 181, 177, 136, 163, 121, 114, 132, 94, 114, 134, 110, 163, 123, 159, 170, 121, 166, 121, 125, 134, 103, 125, 121, 128, 114, 132, 96, 136, 76, 150, 121, 125, 188, 83, 188, 85, 121, 110, 89, 107, 98, 89, 114, 98, 89, 130, 74, 132, 96, 89, 130, 71, 123, 89, 110, 119, 112, 134, 136, 145, 150, 175, 154, 188, 166, 175, 172, 166, 159, 148, 141, 125, 128, 112, 130, 101, 130, 132, 132, 143, 128, 168, 123, 130, 128, 123, 123, 116, 119, 132, 123, 121, 119, 101, 130, 85, 143, 103, 157, 148, 92, 181, 65, 145, 94, 92, 119, 80, 119, 92, 107, 89, 98, 85, 105, 87, 101, 105, 80, 121, 83, 125, 98, 125, 130, 125, 163, 134, 175, 159, 181, 168, 163, 177, 184, 150, 159, 152, 119, 141, 101, 134, 98, 130, 132, 136, 143, 139, 159, 125, 145, 121, 132, 130, 114, 132, 128, 128, 125, 132, 112, 110, 114, 103, 161, 83, 199, 114, 139, 143, 85, 128, 103, 83, 128, 83, 96, 125, 60, 128, 83, 87, 116, 74, 105, 105, 96, 114, 114, 107, 145, 112, 152, 154, 143, 186, 152, 172, 184, 172, 168, 188, 172, 172, 154, 141, 157, 96, 143, 103, 105, 134, 114, 159, 121, 157, 163, 123, 145, 132, 119, 143, 125, 121, 150, 103, 145, 80, 125, 110, 98, 141, 112, 181, 96, 150, 119, 98, 139, 67, 123, 103, 71, 121, 85, 87, 110, 80, 110, 85, 98, 110, 92, 110, 119, 103, 125, 123, 107, 154, 121, 161, 154, 154, 175, 186, 172, 179, 188, 181, 163, 159, 148, 125, 116, 128, 103, 112, 125, 121, 152, 119, 161, 141, 132, 141, 121, 132, 130, 112, 139, 112, 128, 105, 125, 83, 116, 96, 110, 141, 105, 188, 107, 157, 128, 89, 132, 89, 80, 116, 71, 105, 98, 83, 110, 89, 96, 112, 89, 107, 101, 94, 110, 103, 112, 121, 125, 141, 139, 154, 163, 159, 172, 184, 170, 184, 181, 163, 184, 130, 161, 123, 107, 132, 80, 110, 121, 110, 163, 128, 150, 181, 116, 152, 134, 112, 143, 114, 136, 125, 121, 130, 119, 76, 143, 83, 116, 150, 105, 199, 101, 166, 121, 96, 132, 76, 112, 98, 89, 105, 98, 96, 98, 87, 92, 98, 98, 101, 107, 112, 110, 119, 114, 119, 139, 128, 163, 157, 177, 179, 179, 186, 184, 168, 181, 166, 175, 145, 152, 134, 105, 119, 85, 112, 101, 134, 152, 136, 168, 152, 139, 134, 143, 112, 139, 128, 132, 105, 94, 143, 71, 154, 116, 134, 154, 105, 141, 103, 107, 123, 67, 130, 74, 85, 114, 65, 110, 85, 101, 107, 92, 121, 96, 110, 107, 105, 112, 110, 110, 114, 121, 114, 139, 134, 163, 154, 188, 188, 193, 204, 190, 177, 163, 148, 123, 125, 107, 119, 119, 110, 139, 141, 114, 157, 130, 116, 152, 107, 134, 119, 101, 119, 98, 114, 123, 101, 145, 76, 103, 134, 56, 179, 112, 168, 161, 114, 152, 74, 107, 89, 56, 114, 69, 112, 87, 105, 103, 94, 119, 92, 112, 103, 94, 116, 89, 119, 128, 121, 161, 141, 170, 179, 159, 202, 163, 170, 197, 141, 188, 161, 161, 177, 128, 157, 107, 114, 107, 78, 125, 105, 136, 168, 136, 159, 163, 123, 136, 121, 119, 103, 119, 130, 98, 168, 116, 154, 159, 119, 143, 110, 107, 116, 78, 125, 92, 92, 121, 76, 123, 87, 114, 107, 98, 128, 76, 123, 98, 110, 121, 103, 136, 105, 132, 121, 114, 130, 123, 128, 163, 159, 181, 195, 181, 204, 154, 172, 145, 119, 148, 114, 130, 148, 121, 157, 130, 139, 145, 96, 170, 98, 128, 134, 98, 134, 101, 132, 114, 125, 141, 76, 125, 123, 69, 161, 121, 157, 161, 134, 141, 110, 112, 105, 71, 105, 65, 89, 96, 85, 107, 94, 119, 101, 116, 103, 101, 107, 96, 107, 119, 121, 141, 148, 157, 166, 163, 170, 154, 152, 168, 150, 168, 161, 161, 186, 128, 159, 119, 105, 119, 76, 128, 92, 130, 157, 128, 145, 161, 119, 148, 112, 112, 116, 85, 94, 110, 98, 123, 148, 145, 154, 134, 119, 105, 114, 103, 107, 116, 101, 110, 105, 103, 105, 96, 110, 87, 132, 85, 107, 123, 89, 141, 101, 130, 130, 110, 132, 112, 128, 136, 125, 159, 159, 159, 188, 168, 186, 177, 166, 166, 132, 134, 128, 103, 139, 121, 116, 168, 116, 166, 123, 136, 141, 105, 141, 96, 128, 132, 110, 130, 116, 139, 87, 143, 130, 85, 159, 119, 159, 152, 150, 134, 119, 125, 98, 96, 101, 101, 89, 105, 110, 101, 101, 110, 107, 112, 119, 107, 107, 105, 107, 110, 103, 116, 139, 125, 166, 154, 154, 161, 148, 161, 148, 161, 159, 145, 181, 150, 141, 154, 119, 121, 123, 116, 116, 128, 141, 145, 121, 152, 136, 128, 145, 103, 141, 110, 103, 145, 56, 166, 110, 119, 188, 107, 175, 107, 134, 128, 94, 145, 101, 123, 114, 103, 123, 87, 110, 96, 105, 105, 85, 112, 80, 101, 103, 98, 114, 110, 125, 119, 123, 130, 123, 130, 148, 143, 159, 161, 166, 179, 157, 159, 163, 136, 143, 128, 132, 130, 116, 148, 116, 134, 141, 125, 141, 116, 143, 121, 123, 128, 125, 121, 125, 125, 132, 132, 130, 105, 105, 152, 62, 141, 152, 128, 148, 134, 130, 119, 110, 114, 103, 107, 114, 94, 110, 94, 96, 112, 87, 119, 101, 110, 110, 105, 116, 96, 130, 116, 130, 148, 139, 157, 150, 163, 152, 154, 148, 152, 166, 166, 150, 172, 172, 145, 148, 136, 119, 119, 114, 112, 114, 134, 136, 130, 134, 139, 139, 130, 121, 130, 125, 112, 128, 67, 161, 107, 112, 175, 114, 161, 114, 130, 130, 112, 119, 132, 110, 128, 112, 105, 105, 105, 94, 89, 103, 78, 107, 89, 103, 114, 107, 139, 107, 134, 112, 119, 132, 107, 141, 134, 159, 157, 157, 170, 166, 163, 148, 172, 143, 148, 143, 119, 130, 125, 121, 121, 134, 125, 150, 121, 121, 145, 116, 132, 123, 136, 130, 121, 132, 119, 121, 125, 67, 114, 154, 53, 170, 150, 134, 170, 132, 132, 132, 110, 116, 103, 101, 101, 92, 107, 78, 112, 105, 94, 112, 96, 110, 89, 110, 105, 105, 130, 114, 123, 143, 130, 157, 139, 168, 152, 161, 170, 148, 184, 163, 145, 172, 157, 139, 134, 130, 107, 114, 121, 96, 125, 125, 132, 152, 123, 145, 150, 123, 123, 128, 105, 134, 85, 96, 177, 74, 168, 152, 128, 163, 112, 125, 132, 110, 112, 123, 101, 110, 101, 92, 101, 94, 92, 101, 98, 87, 121, 94, 114, 119, 112, 130, 110, 123, 114, 123, 130, 121, 143, 143, 166, 157, 157, 168, 179, 159, 154, 175, 152, 132, 154, 125, 116, 154, 110, 125, 139, 132, 134, 119, 130, 132, 125, 132, 119, 134, 125, 123, 121, 121, 116, 134, 38, 154, 141, 60, 220, 130, 152, 175, 112, 123, 128, 103, 107, 94, 94, 98, 87, 103, 83, 107, 116, 94, 116, 94, 94, 101, 107, 121, 105, 154, 128, 136, 154, 139, 161, 143, 163, 161, 159, 161, 150, 161, 168, 132, 168, 152, 136, 121, 130, 98, 119, 116, 96, 134, 128, 143, 141, 125, 143, 141, 110, 128, 112, 116, 130, 98, 60, 202, 74, 145, 197, 107, 184, 114, 112, 141, 98, 110, 125, 103, 114, 103, 89, 112, 85, 107, 107, 94, 96, 119, 103, 116, 114, 112, 125, 114, 116, 130, 116, 141, 128, 148, 150, 157, 163, 159, 152, 179, 163, 139, 159, 163, 123, 136, 139, 103, 143, 116, 114, 125, 132, 132, 119, 141, 119, 145, 123, 128, 141, 125, 125, 119, 114, 123, 94, 40, 204, 42, 159, 208, 112, 177, 154, 96, 139, 105, 101, 114, 87, 105, 89, 89, 96, 87, 98, 116, 78, 105, 96, 96, 114, 105, 103, 132, 125, 134, 130, 148, 136, 141, 154, 152, 159, 157, 175, 150, 166, 193, 123, 170, 177, 105, 148, 125, 96, 139, 128, 105, 141, 134, 141, 139, 128, 134, 134, 125, 114, 114, 119, 134, 105, 134, 33, 195, 83, 112, 240, 121, 145, 136, 128, 125, 110, 119, 110, 105, 101, 92, 105, 85, 98, 96, 87, 96, 114, 103, 107, 125, 107, 121, 119, 112, 123, 125, 139, 132, 150, 152, 157, 168, 157, 168, 159, 161, 163, 139, 141, 188, 128, 134, 154, 101, 141, 105, 110, 150, 110, 143, 152, 110, 148, 136, 128, 114, 152, 101, 125, 105, 121, 58, 87, 199, 0, 233, 184, 92, 199, 112, 92, 143, 85, 114, 107, 96, 107, 92, 87, 110, 80, 101, 92, 94, 114, 78, 110, 114, 123, 123, 114, 132, 123, 134, 139, 134, 143, 159, 148, 157, 168, 166, 159, 170, 172, 139, 150, 163, 107, 141, 121, 103, 141, 112, 134, 130, 141, 157, 112, 148, 128, 121, 136, 112, 123, 110, 134, 119, 107, 33, 222, 33, 143, 247, 98, 145, 154, 98, 123, 107, 107, 116, 87, 92, 96, 80, 92, 98, 74, 101, 83, 112, 98, 114, 128, 110, 125, 114, 130, 119, 141, 134, 143, 157, 159, 159, 175, 154, 172, 150, 154, 181, 141, 152, 188, 139, 136, 152, 94, 150, 107, 119, 139, 123, 148, 141, 134, 136, 132, 123, 130, 116, 121, 112, 128, 60, 83, 202, 4, 213, 193, 110, 143, 136, 94, 114, 105, 96, 114, 94, 101, 112, 87, 92, 94, 89, 110, 83, 116, 112, 96, 121, 110, 132, 123, 123, 136, 130, 139, 139, 148, 154, 159, 161, 159, 175, 148, 159, 177, 139, 145, 177, 116, 154, 119, 116, 145, 94, 139, 141, 114, 145, 139, 114, 141, 121, 128, 119, 116, 101, 130, 98, 116, 22, 161, 107, 49, 255, 119, 132, 154, 114, 112, 121, 110, 107, 103, 103, 92, 96, 78, 101, 87, 76, 105, 98, 94, 112, 112, 114, 134, 110, 125, 143, 123, 150, 141, 157, 152, 159, 172, 148, 166, 168, 132, 184, 148, 143, 168, 163, 119, 152, 110, 121, 130, 107, 143, 103, 150, 125, 114, 139, 134, 116, 134, 123, 110, 110, 105, 29, 222, 11, 141, 231, 96, 166, 130, 94, 119, 107, 94, 130, 89, 103, 119, 96, 85, 112, 83, 114, 94, 96, 114, 105, 107, 128, 114, 123, 152, 107, 143, 139, 132, 157, 136, 161, 159, 161, 166, 152, 161, 163, 152, 161, 139, 168, 125, 139, 125, 141, 112, 132, 130, 130, 130, 125, 141, 136, 112, 136, 128, 110, 128, 89, 150, 80, 130, 15, 199, 67, 69, 255, 105, 141, 150, 114, 130, 112, 101, 136, 89, 105, 101, 101, 85, 96, 87, 94, 96, 103, 107, 110, 110, 123, 125, 116, 125, 121, 136, 145, 150, 152, 163, 161, 166, 163, 163, 170, 139, 163, 157, 143, 148, 166, 128, 143, 114, 132, 116, 107, 150, 103, 134, 136, 121, 134, 121, 114, 145, 103, 121, 87, 65, 217, 2, 170, 186, 112, 139, 152, 105, 103, 130, 92, 112, 107, 112, 98, 119, 101, 94, 123, 85, 103, 110, 94, 116, 107, 103, 128, 121, 123, 134, 123, 134, 139, 128, 148, 141, 145, 157, 168, 166, 150, 170, 159, 143, 179, 134, 154, 141, 125, 150, 107, 139, 128, 128, 125, 152, 98, 136, 130, 114, 136, 119, 110, 130, 134, 89, 145, 31, 177, 105, 38, 249, 114, 141, 145, 121, 119, 134, 96, 121, 128, 80, 116, 110, 87, 98, 98, 89, 98, 96, 98, 114, 110, 114, 114, 123, 107, 132, 112, 150, 128, 143, 163, 132, 170, 150, 161, 163, 145, 152, 157, 141, 145, 159, 141, 148, 123, 132, 139, 98, 148, 119, 121, 132, 125, 125, 132, 121, 136, 119, 128, 112, 130, 116, 49, 226, 42, 114, 233, 123, 143, 148, 121, 110, 125, 112, 116, 110, 110, 116, 98, 98, 119, 78, 112, 87, 92, 110, 98, 112, 107, 119, 105, 130, 112, 130, 125, 134, 145, 125, 157, 152, 150, 163, 152, 168, 157, 152, 152, 145, 159, 141, 145, 132, 145, 130, 114, 150, 119, 132, 125, 132, 123, 130, 114, 143, 116, 125, 107, 150, 69, 83, 229, 13, 186, 179, 107, 152, 134, 105, 125, 112, 112, 116, 101, 112, 119, 78, 107, 96, 96, 101, 74, 116, 87, 105, 114, 105, 116, 114, 125, 119, 134, 125, 139, 150, 136, 157, 143, 161, 154, 154, 154, 154, 157, 143, 148, 159, 150, 145, 128, 159, 107, 136, 132, 116, 128, 128, 119, 123, 123, 125, 139, 107, 141, 94, 143, 103, 123, 78, 98, 197, 0, 206, 199, 103, 157, 130, 105, 112, 116, 110, 103, 101, 103, 112, 78, 105, 87, 94, 94, 94, 98, 110, 103, 123, 119, 107, 134, 130, 123, 145, 132, 136, 150, 143, 161, 150, 157, 163, 150, 150, 154, 159, 143, 152, 159, 143, 128, 145, 143, 112, 150, 125, 130, 125, 134, 136, 130, 128, 130, 148, 101, 141, 83, 92, 195, 26, 181, 170, 123, 143, 132, 130, 112, 116, 119, 110, 103, 112, 105, 107, 92, 96, 98, 89, 105, 80, 110, 107, 103, 107, 114, 114, 114, 123, 123, 136, 139, 125, 157, 145, 134, 161, 157, 154, 152, 170, 157, 157, 157, 143, 184, 116, 157, 154, 112, 150, 139, 116, 141, 116, 132, 128, 128, 141, 125, 139, 114, 139, 125, 114, 123, 116, 125, 42, 226, 20, 132, 240, 96, 157, 128, 116, 105, 114, 114, 98, 110, 98, 83, 94, 85, 74, 94, 83, 94, 112, 96, 98, 125, 110, 107, 119, 134, 119, 130, 143, 145, 143, 145, 161, 161, 148, 172, 154, 152, 159, 157, 163, 148, 143, 163, 110, 132, 154, 92, 143, 128, 119, 123, 128, 139, 121, 123, 134, 136, 103, 119, 114, 116, 13,
};
//audio output is on pin 11

void setup() { 
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<LED_TYPE,DATA_PIN,RGB>(leds,NUM_LEDS);
  LEDS.setBrightness(84);
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void loop() { 

randNumber = random(500, 5000);  

  static uint8_t hue = 0;
  Serial.print("x");
  // First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show(); 
    startPlayback(sample, sizeof(sample));//Play sizzle sound
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);
  }
  Serial.print("x");
  delay (randNumber);
}
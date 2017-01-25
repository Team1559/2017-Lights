#include <RGBConverter.h>
#include <Adafruit_NeoPixel.h>
#define PIN 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(120, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}
/* LIGHT SEQUENCES
 *  cylonEye
 *  theFinalCountdown
 *  fadeFromTo
 *  crawling
 *  rainbowFade
 */

void loop() {
  rainbowFade();
}

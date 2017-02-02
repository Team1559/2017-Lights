#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#define PIN 7
#define I2C_ADDRESS 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(120, PIN, NEO_GRB + NEO_KHZ800);
byte data[3] = {0, 0, 0};

void setup() {
  strip.begin();
  strip.show();
  //  Wire.begin(I2C_ADDRESS);
  //  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

/* LIGHT SEQUENCES
    cylonEye(int r, int g, int b, int r2, int g2, int b2, int length, int delay);
    theFinalCountdown();
    fadeFromTo(int r, int g, int b, int r2, int g2, int b2);
    crawling(int r, int g, int b, int r2, int g2, int b2, boolean left, int delay);
    rainbowFade();
    readingRainbowFade(int centerAngle, int range, int delay);
    seizureMode(int delay);
    pulseGreen();
    dingDingDing();
*/

void loop() {
  switch (data[0]) {
    case 1://Currently Vestigial
      cylonEye(255, 0, 0, 0, 0, 255, 2, 5);
      break;
    case 2://Final 30 Sec
      theFinalCountdown();
      break;
    case 3://Traction
      if (data[1] == 1) {//Blue
        crawling(0, 0, 0, 0, 0, 255, true, 90);
      }
      else {//Red
        crawling(0, 0, 0, 255, 0, 0, true, 90);
      }
      break;
    case 4://Mecanum
      if (data[1] == 1) {
        readingRainbowFade(180, 60, 5);
      }
      else {
        readingRainbowFade(340, 30, 20);
      }
      break;
    case 5://Auto
      seizureMode(0);
      break;
    case 6://Disabled
      pulseGreen();
      break;
    case 7://Auto-Aim
      aim(data[2]);
      break;
    case 8://aim tester
      for (int i = 0; i < 20; i += .5) {
        aim(i);
        delay(200);
      }
      break;
    default:
      setAll(255, 255, 255);
      break;
  }
}

//void receiveEvent(){
//  int i = 0;
//  while(Wire.available()){
//    data[i] = Wire.read();
//    i++;
//  }
//}

void serialEvent() {
  int i = 0;
  while (Serial.available()) {
    data[i] = Serial.read() - 48;
    i++;
  }
}


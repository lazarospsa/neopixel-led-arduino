#include <Adafruit_NeoPixel.h>

// How many internal neopixels do we have? some boards have more than one!
#define NUMPIXELS        1
#define PHOTONIO        28
#define THERMONIO        27

Adafruit_NeoPixel pixels(NUMPIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(115200);

#if defined(NEOPIXEL_POWER)
  // If this board has a power control pin, we must set it to output and high
  // in order to enable the NeoPixels. We put this in an #if defined so it can
  // be reused for other boards without compilation errors
  pinMode(NEOPIXEL_POWER, OUTPUT);
  digitalWrite(NEOPIXEL_POWER, HIGH);
#endif

  // pinMode(PHOTONIO, OUTPUT);
  // pinMode(THERMONIO, OUTPUT);


  sensorValue = analogRead(PHOTONIO);
  sensorValue2 = analogRead(THERMONIO);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(20); // not so bright
}

// the loop routine runs over and over again forever:
void loop() {
  // say hi
  Serial.println("Hello!");
  Serial.println(sensorValue);
  Serial.println(sensorValue2);
  
  
  
  for (int brightness = 1; brightness <= 255; brightness++) {
    pixels.fill(0xFF0000);
    pixels.setBrightness(brightness);
    delay(50);
    pixels.show();
  }
  
  for (int brightness = 1; brightness <= 255; brightness++) {
    pixels.fill(0x0000FF);
    pixels.setBrightness(brightness);
    delay(50);
    pixels.show();
  }  
  for (int brightness = 1; brightness <= 255; brightness++) {
    pixels.fill(0x00FF00);
    pixels.setBrightness(brightness);
    delay(50);
    pixels.show();
  }

  // turn off
  pixels.fill(0x000000);
  pixels.show();
  delay(500); // wait half a second
}
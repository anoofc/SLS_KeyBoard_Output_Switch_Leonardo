#define DEBUG 1

#define LED_PIN 3
#define NUM_PIXELS 20
#define SWITCH 2

#define KEY 't'

#define DEBOUNCE 100

#define RED 255,0,0
#define GREEN 0,255,0
#define BLUE 0,0,255


#include <Arduino.h>
#include <Keyboard.h>
#include <Adafruit_NeoPixel.h>  

Adafruit_NeoPixel strip(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

bool lastState = 0;
uint32_t lastMillis = 0;

void readSwitch(){
  bool state = digitalRead(SWITCH);
  if (!state && state != lastState) {
    strip.fill(strip.Color(BLUE));
    strip.show();
    lastState = state;
    Keyboard.press(KEY);
    if (DEBUG){Serial.println("Key Pressed");}
    lastMillis = millis();
  } else if (state && state != lastState) {
    lastState = state;
    Keyboard.releaseAll();
    strip.fill(strip.Color(RED));
    strip.show();
    if (DEBUG){Serial.println("Key Released");}
    lastMillis = millis();
  }
}

void stripInit(){
  strip.begin();
  strip.setBrightness(255);
  strip.clear();
  strip.fill(strip.Color(RED));
  strip.show();
}

void setup() {
  Serial.begin(115200);
  Keyboard.begin();
  stripInit();
  pinMode(SWITCH, INPUT_PULLUP);
}

void loop() {
  if (millis() - lastMillis<DEBOUNCE){return;}
  readSwitch();
}
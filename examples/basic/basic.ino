#include <LongPushSwitch.h>

LongPushSwitch longPushSwitch =  LongPushSwitch(2, 1000, shortPushFunc, longPushFunc, FALLING);

void setup() {
  pinMode(2, INPUT_PULLUP);
}

void shortPushFunc() {
  Serial.println("Short push");
}

void longPushFunc() {
  Serial.println("Long push");
}

void loop() {
  longPushSwitch.check();
}

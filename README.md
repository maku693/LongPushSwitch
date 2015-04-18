# LongPushSwitch

An Arduino library to detect push and press separately.

## Usage

``` cpp
#include <LongPushSwitch.h>

LongPushSwitch longPushSwitch =  LongPushSwitch(2, 1000, shortPushFunc, longPushFunc, FALLING);

void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT_PULLUP);
}

void shortPushFunc() { // Called when just pressed.
  Serial.println("Short push");
}

void longPushFunc() { // Called when pressed for a second.
  Serial.println("Long push");
}

void loop() {
  longPushSwitch.check(); // You need to check button status in every loop...
}
```

## Reference
### LongPushSwitch::LongPushSwitch(pin, time, shortPushFunc, longPushFunc, mode)
Sets pin, time (by milli seconds) to regard as "Long" push, functions, and when the function should be called.

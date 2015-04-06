/*
  LongPushSwitch.cpp
  (c) 2015 Shota HAMADA
  This library is released under MIT License.
*/

#include <Arduino.h>
#include "LongPushSwitch.h"

LongPushSwitch::LongPushSwitch(
	int pin,
	uint32_t time,
	void (*shortPushFunc)(),
	void (*longPushFunc)(),
	int mode
) {
	_pin = pin;
	_time = 0;
	_shortPushFunc = shortPushFunc;
	_longPushFunc = longPushFunc;
	_mode = mode;

	_lastPushed = 0;
	if (_mode == FALLING) {
	    _pushedState = LOW;
	} else {
	    _pushedState = HIGH;
	}
	_isLongPush = false;
};

void LongPushSwitch::check() {
	if (digitalRead(_pin) == _pushedState) {
		if (_lastPushed == 0) {
			_lastPushed = millis();
		} else if (millis() - _lastPushed > 1000 && _isLongPush == false) {
			_longPushFunc();
			_isLongPush = true;
		}
	} else if (_lastPushed != 0) {
		if (_isLongPush == false) {
			_shortPushFunc();
		} else {
			_isLongPush = false;
		}
		_lastPushed = 0;
	}
};

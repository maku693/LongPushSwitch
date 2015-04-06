/*
  LongPushSwitch.h
  (c) 2015 Shota HAMADA
  This library is released under MIT License.
*/

#ifndef LongPushSwitch_h
#define LongPushSwitch_h

#include <stdint.h>

class LongPushSwitch {
	public:
		LongPushSwitch(int pin, uint32_t time, void (*shortPushFunc)(), void (*longPushFunc)(), int mode);
		void check();

	private:
		uint32_t _pin;
		uint32_t _pushedState;
		uint32_t _time;
		uint32_t _lastPushed;

		void (*_shortPushFunc)();
		void (*_longPushFunc)();

		int _mode;

		bool _isLongPush;
};

#endif

#pragma once

#include "Event.h"

namespace Entropy
{
	class ENTROPY_API KeyEvent : public Event
	{
	public:
		inline int getKeyCode() const
		{
			return keyCode;
		}

		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_KEYBOARD | EVENT_CATEGORY_INPUT);
	protected:
		KeyEvent(int keyCode) : keyCode(keyCode) {}

		int keyCode;
	};

	class ENTROPY_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount) :
			KeyEvent(keyCode), repeatCount(repeatCount) {};

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KEY_PRESSED)
	private:
		int repeatCount;
	};

	class ENTROPY_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode) :
			KeyEvent(keyCode) {};

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KEY_RELEASED)
	};
}

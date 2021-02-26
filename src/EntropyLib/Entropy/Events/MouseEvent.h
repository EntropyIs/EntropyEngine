#pragma once

#include "Event.h"

namespace Entropy
{
	class ENTROPY_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) :
			x(x), y(y) {};

		inline float getX() const;
		inline float getY() const;

		std::string toString() const override;

		EVENT_CLASS_TYPE(MOUSE_MOVED_E)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)

	private:
		float x, y;
	};

	class ENTROPY_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) :
			xOffset(xOffset), yOffset(yOffset) {};

		inline float getXOffset() const;
		inline float getYOffset() const;

		std::string toString() const override;

		EVENT_CLASS_TYPE(MOUSE_SCROLLED)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)

	private:
		float xOffset, yOffset;
	};

	class ENTROPY_API MouseButtonEvent : public Event
	{
	public:
		inline int getButton() const;

		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE_BUTTON | EVENT_CATEGORY_INPUT);

	protected:
		MouseButtonEvent(int mouseButton) : mouseButton(mouseButton) {}

		int mouseButton;
	};

	class ENTROPY_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int mouseButton) :
			MouseButtonEvent(mouseButton) {};

		std::string toString() const override;

		EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESSED)
	};

	class ENTROPY_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int mouseButton) :
			MouseButtonEvent(mouseButton) {};

		std::string toString() const override;

		EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED)
	};
}
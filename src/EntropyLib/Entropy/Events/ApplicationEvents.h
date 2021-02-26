#pragma once

#include "Event.h"

namespace Entropy
{
	class ENTROPY_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) :
			width(width), height(height) {};

		inline unsigned int getWidth()
		{
			return width;
		}

		inline unsigned int getHeight()
		{
			return height;
		}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowREsizeEvent: " << width << ", " << height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WINDOW_RESIZE)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
	private:
		unsigned int width, height;
	};

	class ENTROPY_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WINDOW_CLOSE)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
	};

	class ENTROPY_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(APP_TICK)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
	};

	class ENTROPY_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(APP_UPDATE)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
	};

	class ENTROPY_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(APP_RENDER)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
	};
}

#pragma once

#include "ecpch.h"

#include "..\Tools\API.h"
//#include "..\Tools\Log.h"

namespace Entropy
{
	enum class EventType {
		NONE = 0,
		WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS, WINDOW_LOST_FOCUS, WINDOW_MOVED,
		APP_TICK, APP_UPDATE, APP_RENDER,
		KEY_PRESSED, KEY_RELEASED,
		MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_MOVED_E, MOUSE_SCROLLED
	};

	enum EventCategory {
		EVENT_CATEGORY_NONE = 0,
		EVENT_CATEGORY_APPLICATION = BIT(0),
		EVENT_CATEGORY_INPUT = BIT(1),
		EVENT_CATEGORY_KEYBOARD = BIT(2),
		EVENT_CATEGORY_MOUSE = BIT(3),
		EVENT_CATEGORY_MOUSE_BUTTON = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
                               virtual EventType getEventType() const override { return getStaticType(); }\
                               virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class ENTROPY_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const
		{
			return getName();
		};

		inline bool isInCategory(EventCategory category)
		{
			return getCategoryFlags() & category;
		};

	protected:
		bool handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.getEventType() == T::getStaticType())
			{
				m_Event.handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		};

	private:
		Event& m_Event;
	};
}
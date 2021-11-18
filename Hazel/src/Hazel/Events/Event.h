#pragma once
#include"Hazel/Core.h"
#include"Hazel/hzpch.h"

namespace Hazel {
	enum  class EventType {
		None = 0,
		WinddowClosed, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum  EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(1),
		EventCategoryInput = BIT(2),
		EventCategoryKeyboard = BIT(3),
		EventCategoryMouse = BIT(4),
		EventCategoryMouseButton = BIT(5)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticEventType(){return type;}\
							   virtual EventType GetEventType()const override{return GetStaticEventType();}\
							   virtual const char*GetName()const override{return #type;}
	//const和override分别限制函数为const和函数为override

#define EVENT_CLASS_CATEGORY(category) virtual int GetEventCategoryFlags()const override{return (int)category;}

	//上面的enum似乎不用__declspec(export)
	class HAZEL_API Event {
	public:
		virtual EventType GetEventType()const = 0;
		virtual const char* GetName()const = 0;
		virtual int GetEventCategoryFlags()const = 0;
		virtual std::string ToString()const { return GetName(); }
		inline bool IsInCategory(EventCategory category) { return GetEventCategoryFlags() & category; }
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher {
		template<typename T>
		using EventFunc = std::function<bool>(T&);
	public:
		EventDispatcher(Event& event) :m_Event(event)
		{

		}
		template<typename T>
		bool Dispatch(EventFunc<T>func) {
			if (m_Event.GetEventType() == T::GetStaticEventType()) {
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
}
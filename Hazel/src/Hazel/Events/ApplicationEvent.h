#pragma once
#include"Event.h"
#include"Hazel/hzpch.h"

namespace Hazel {
	class WindowResizeEvent :public Event {
	public:
		WindowResizeEvent(float width, float height) :m_Width(width), m_Height(height) {}
		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent:" << m_Width << " ," << m_Height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(EventType::WindowResize)
			EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)
	private:
		float m_Width;
		float m_Height;
	};

	class WindowClosedEvent :public Event {
		virtual std::string ToString()const override
		{
			std::stringstream ss;
			ss << "WindowClosedEvent";
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
			EVENT_CLASS_TYPE(EventType::WinddowClosed)
	};

	class AppTickEvent :public Event {
		virtual std::string ToString()const override
		{
			std::stringstream ss;
			ss << "AppTickEvent";
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
			EVENT_CLASS_TYPE(EventType::AppTick)
	};

	class AppUpdateEvent :public Event {
		virtual std::string ToString()const override
		{
			std::stringstream ss;
			ss << "AppUpdateEvent";
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
			EVENT_CLASS_TYPE(EventType::AppUpdate)
	};

	class AppRenderEvent :public Event {
		virtual std::string ToString()const override
		{
			std::stringstream ss;
			ss << "AppRenderEvent";
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
			EVENT_CLASS_TYPE(EventType::AppRender)
	};
}
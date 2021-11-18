#pragma once
#include"Event.h"
#include"Hazel/hzpch.h"
namespace Hazel {
	class HAZEL_API MouseMovedEvent :public Event
	{
	public:
		MouseMovedEvent(float mouseX, float mouseY) :m_MouseX(mouseX), m_MouseY(mouseY) {}
		virtual std::string ToString()const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent:" << m_MouseX << " ," << m_MouseY;
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
			EVENT_CLASS_TYPE(EventType::MouseMoved)
	private:
		float m_MouseX;
		float m_MouseY;
	};

	class HAZEL_API MouseScrolledEvent :public Event
	{
	public:
		MouseScrolledEvent(float offsetX, float offsetY) :m_OffsetX(offsetX), m_OffsetY(offsetY) {}

		inline float GetXOffset() { return m_OffsetX; }
		inline float GetYOffset() { return m_OffsetY; }

		virtual std::string ToString()const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent:" << m_OffsetX << " ," << m_OffsetY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
			EVENT_CLASS_TYPE(EventType:::MouseScrolled)
	private:
		float m_OffsetX;
		float m_OffsetY;
	};

	class MouseButton :public Event
	{
	public:
		MouseButton(int button) :m_Button(button) {}
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		int m_Button;
	};

	class HAZEL_API MouseButtonPressed :public MouseButton
	{
	public:
		MouseButtonPressed(int button) :MouseButton(button) {}
		virtual std::string ToString()const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed:" << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(EventType::MouseButtonPressed)
	};

	class HAZEL_API MouseButtonReleased :public MouseButton
	{
	public:
		MouseButtonReleased(int button) :MouseButton(button) {}
		virtual std::string ToString()const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleased:" << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(EventType::MouseButtonReleased)
	};
}
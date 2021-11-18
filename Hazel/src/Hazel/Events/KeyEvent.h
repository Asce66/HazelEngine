#pragma once
#include"Event.h"
#include"Hazel/hzpch.h"
namespace Hazel {
	class KeyEvent :public Event {
	public:
		KeyEvent(int keyCode) :m_KeyCode(keyCode) {}
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryInput | EventCategory::EventCategoryKeyboard);
	protected:
		int m_KeyCode;
	};

	class HAZEL_API KeyPressedEvent :public KeyEvent {
	public:
		KeyPressedEvent(int keyCode, int repeatedCount) :
			KeyEvent(keyCode), m_RepeatedCount(repeatedCount)
		{

		}

		inline int GetRepeatedCount() { return m_RepeatedCount; }

		virtual std::string ToString()const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent:" << m_KeyCode << "(" << m_RepeatedCount<<" repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(EventType::KeyPressed)
	private:
		int m_RepeatedCount;
	};

	class HAZEL_API KeyReleasedEvent :public KeyEvent 
	{
	public:
		KeyReleasedEvent(int keyCode) :KeyEvent(keyCode) {}
		virtual std::string ToString()const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent:" << m_KeyCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(EventType::KeyReleased)
	};
}
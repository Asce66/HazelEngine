#pragma once
#include"hzpch.h"
#include"Hazel/Core.h"
#include"Hazel/Events/Event.h"

namespace Hazel {
	struct WindowPrors {
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		WindowPrors(std::string title = "Hazel Window", unsigned int width = 1920, unsigned int height = 1080)
			:Title(title), Width(width), Height(height)
		{
		}
	};

	class Window {
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~Window() = 0;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth()const = 0;
		virtual unsigned int GetHeight()const = 0;

		//window attributes
		virtual void SetEventCallback(EventCallbackFunc& func) = 0;
		virtual void SetSync(bool enable) = 0;
		virtual bool IsSync()const = 0;

		static Window* Create(const WindowPrors& props = WindowPrors());
	};
}
#include"hzpch.h"
#include"Application.h"
#include"Events/ApplicationEvent.h"
#include <Hazel/Log.h>
namespace Hazel {
	void Application::Run() {
		Hazel::WindowResizeEvent wr(1920, 1080);
		if (wr.IsInCategory(EventCategory::EventCategoryApplication)) {
			HZ_CORE_WARN(wr.ToString());
		}
		while (true);
	}
	Application::Application() {}
	Application::~Application() {}
}
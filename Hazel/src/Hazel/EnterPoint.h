#pragma once
#ifdef HZ_PLATFORM_WINDOWS
extern Hazel::Application* Hazel::CreateApplication();
int main(int argn, char** argv) {
	Hazel::Log::Init();
	HZ_CORE_INFO("Hello!I am Hazel Engine");
	HZ_CORE_WARN("Hello!I am Hazel Engine");
	auto app = Hazel::CreateApplication();
	app->Run();
	return 0;
}
#endif // HZ_PLATFORM_WINDOWS
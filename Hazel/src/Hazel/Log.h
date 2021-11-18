#pragma once
#include"Core.h"
#include"hzpch.h"
#include"spdlog/spdlog.h"
namespace Hazel {
	class HAZEL_API Log
	{
	public:
		static void Init();
		Log() {}
		~Log() {}
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_Clientlogger; }
	private:
		static std::shared_ptr<spdlog::logger>s_CoreLogger;
		static std::shared_ptr<spdlog::logger>s_Clientlogger;
	};
}
//engine
#define HZ_CORE_ERROR(...) ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_WARN(...) ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_INFO(...) ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)

//client
#define HZ_CLIENT_ERROR(...) ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CLIENT_WARN(...) ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CLIENT_INFO(...) ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
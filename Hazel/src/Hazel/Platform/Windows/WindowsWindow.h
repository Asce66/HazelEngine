#pragma once
#include"Hazel/Window.h"
namespace Hazel {

	class WindowsWindow:public Window
	{
		// ͨ�� Window �̳�
		virtual void OnUpdate() override;
		virtual unsigned int GetWidth() const override;
		virtual unsigned int GetHeight() const override;
		virtual void SetEventCallback(EventCallbackFunc& func) override;
		virtual void SetSync(bool enable) override;
		virtual bool IsSync() const override;
	};
}


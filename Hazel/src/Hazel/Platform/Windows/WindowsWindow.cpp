#include "Hazel/hzpch.h"
#include "WindowsWindow.h"

void Hazel::WindowsWindow::OnUpdate()
{
}

unsigned int Hazel::WindowsWindow::GetWidth() const
{
	return 0;
}

unsigned int Hazel::WindowsWindow::GetHeight() const
{
	return 0;
}

void Hazel::WindowsWindow::SetEventCallback(EventCallbackFunc& func)
{
}

void Hazel::WindowsWindow::SetSync(bool enable)
{
}

bool Hazel::WindowsWindow::IsSync() const
{
	return false;
}

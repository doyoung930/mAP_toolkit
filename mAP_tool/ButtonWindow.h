#pragma once
#include "Window.h"

// 좌측 Button들 모아두는 Wnd
class ButtonWindow : public Window
{
public:
	ButtonWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f));

	void Render();

private:
	std::string FilePath;
	std::string items[5] = { /*"All",*/ "0.5", "0.6", "0.7", "0.8", "0.95" };
};
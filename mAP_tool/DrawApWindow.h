#pragma once
#include "Window.h"

// Category에서 선택한것의 AP를 출력하는 Wnd
class DrawApWindow : public Window
{
public:
	DrawApWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f))
		: Window(Beginname, Wndname, Wndpos, Wndsize, BgColor),
		IndexStr(L"None")
	{}

	void Render();

private:
	void SetRenderText();
	
	std::string FilePath;
	std::wstring IndexStr;
};

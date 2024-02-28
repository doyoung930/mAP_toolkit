#pragma once
#include "Window.h"
#include <vector>
#include <string>

// 0~9, 가, 나, 다... 에 대한 리스트 박스를 출력하는 Wnd
class CategoriesWindow : public Window
{
public:
	CategoriesWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f));

	void Render();

	void RenderUnicode(std::string str, int n);

private:
};

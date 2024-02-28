#pragma once
#include "Window.h"
#include <vector>
#include <string>

class CategoriesWindow : public Window
{
public:
	CategoriesWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f));

	void Render();

	void RenderUnicode(std::string str, int n);

private:
};

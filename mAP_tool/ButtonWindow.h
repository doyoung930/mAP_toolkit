#pragma once
#include "Window.h"

class ButtonWindow : public Window
{
public:
	ButtonWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f));

	void Render();

	friend void SetFilePath(Window* other, std::string text);

private:
	std::string FilePath;
	std::string items[5] = { /*"All",*/ "0.5", "0.6", "0.7", "0.8", "0.95" };
};
#pragma once
#include "Window.h"

class ButtonWindow : public Window
{
public:
	ButtonWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize)
	{}

	void Render();

	friend void SetFilePath(Window* other, std::string text);

private:
	std::string FilePath;
};
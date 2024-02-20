#pragma once
#include "Window.h"

class ButtonWindow : public Window
{
public:
	ButtonWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize);

	void Render();

	friend void SetFilePath(Window* other, std::string text);

private:
	std::string FilePath;
	std::string items[6] = { "All", "0.5", "0.6", "0.7", "0.8", "0.95" };
};
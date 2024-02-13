#pragma once
#include "Window.h"

class ImageWindow : public Window
{
public:
	ImageWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize)
	{}

	void Render();
};
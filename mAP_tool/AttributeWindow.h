#pragma once
#include "Window.h"

class AttributeWindow : public Window
{
public:
	AttributeWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize), IOUStr("")
	{}

	void Render();

	void SetIOU(std::string iou) { IOUStr = iou; }

private:
	std::string IOUStr;
};
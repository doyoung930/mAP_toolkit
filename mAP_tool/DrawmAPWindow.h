#pragma once
#include "Window.h"

// mAP Ãâ·Â
class DrawmAPWindow : public Window
{
public:
	DrawmAPWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f))
		: Window(Beginname, Wndname, Wndpos, Wndsize, BgColor), IOUStr("")
	{}

	void Render();

	void SetIOU(std::string iou) { IOUStr = iou; }

private:
	std::string IOUStr;
};
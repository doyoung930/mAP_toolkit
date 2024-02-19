#pragma once
#include "Window.h"

class ImageWindow : public Window
{
public:
	ImageWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f));

	void Render();

	virtual void ProcessAfterEndRender();

	void RenderUnicode(std::string str);
	
	void TextCentered(std::string text, int BoxSize);

protected:
	std::vector<float> APArray;
};
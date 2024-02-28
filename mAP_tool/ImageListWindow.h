#pragma once
#include "Window.h"

class ImageListWindow : public Window
{
public:
	ImageListWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f))
		: Window(Beginname, Wndname, Wndpos, Wndsize, BgColor),
		IndexStr(L"None")
	{}

	void Render();

	void LoadImageWithPath(std::string path);

private:
	void SetRenderText();
	
	std::string FilePath;
	std::vector<std::string> ImageNames;
	std::wstring IndexStr;
};

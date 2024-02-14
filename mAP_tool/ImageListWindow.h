#pragma once
#include "Window.h"

class ImageListWindow : public Window
{
public:
	ImageListWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize),
		IndexStr("")
	{}

	void Render();

	void LoadImageWithPath(std::string path);

private:
	void SetRenderText();
	
	std::string FilePath;
	std::vector<std::string> ImageNames;
	std::string IndexStr;
};

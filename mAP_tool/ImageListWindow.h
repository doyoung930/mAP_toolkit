#pragma once
#include "Window.h"

class ImageListWindow : public Window
{
public:
	ImageListWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize),
		CurrentSelectIndex(0)
	{}

	void Render();

	void LoadImageWithPath(std::string path);

private:
	int CurrentSelectIndex;
	std::string FilePath;
	std::vector<std::string> ImageNames;
};

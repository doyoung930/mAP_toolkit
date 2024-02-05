#pragma once

#include <string>
#include "ImguiDefine.h"

class Window
{
public:
	// TODO: 빌더 디자인 패턴 사용해보자
	Window(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		:	BeginName(Beginname),
			WndName(Wndname),
			WndPos(Wndpos),
			WndSize(Wndsize)
	{}
	virtual ~Window() {}

	virtual void Render(bool IsCalledSuper = false);

	bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);

protected:
	std::string BeginName;
	std::string WndName;

	ImVec2 WndPos;
	ImVec2 WndSize;

};

class ImageWindow : public Window
{
public:
	ImageWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize)
	{}

	void Render(bool IsCalledSuper = false);
};

class ButtonWindow : public Window
{
public:
	ButtonWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize)
	{}

	void Render(bool IsCalledSuper = false);
};

class ImageListWindow : public Window
{
public:
	ImageListWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize)
	{}
};

class AttributeWindow : public Window
{
public:
	AttributeWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize)
	{}
};

class CategoriesWindow : public Window
{
public:
	CategoriesWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize)
	{}
};


#pragma once

#include <string>
#include "ImguiDefine.h"

class Window
{
public:
	// TODO: ���� ������ ���� ����غ���
	Window(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		:	BeginName(Beginname),
			WndName(Wndname),
			WndPos(Wndpos),
			WndSize(Wndsize)
	{}
	virtual ~Window() {}

	// â ������ �̸� ���� �������� �۾��� ��Ƶ�
	void InitRender();
	void EndRender();

	virtual void Render() = 0;

	bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
	std::string GetFileDirectory();

	std::string ToString(std::wstring value);

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

	void Render();
};

class ButtonWindow : public Window
{
public:
	ButtonWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize)
	{}

	void Render();
};

class ImageListWindow : public Window
{
public:
	ImageListWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize)
	{}

	void Render();
};

class AttributeWindow : public Window
{
public:
	AttributeWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize)
	{}

	void Render();
};

class CategoriesWindow : public Window
{
public:
	CategoriesWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		: Window(Beginname, Wndname, Wndpos, Wndsize)
	{}

	void Render();
};


#pragma once

#include <string>
#include "ImguiDefine.h"

class Window
{
public:
	// TODO: ���� ������ ���� ����غ���
	Window(std::string BeginName, std::string WndName, ImVec2 WndPos, ImVec2 WndSize) {}
	virtual ~Window() {}

	void Render();

protected:
	std::string BeginName;
	std::string WndName;

	ImVec2 WndPos;
	ImVec2 WndSize;

};

class ImageWindow : public Window
{

};


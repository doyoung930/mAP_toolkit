#pragma once
#include "Window.h"

// ��� AP�� �׷����� ����ϴ� Wnd
class GraphWindow : public Window
{
public:
	GraphWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f));

	void Render();
	
	// Text ���Ʒ� ��� ����
	void TextCentered(std::string text, int BoxSize, int n);

};
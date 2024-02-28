#pragma once
#include "Window.h"

// 가운데 AP의 그래프를 출력하는 Wnd
class GraphWindow : public Window
{
public:
	GraphWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f));

	void Render();
	
	// Text 위아래 가운데 정렬
	void TextCentered(std::string text, int BoxSize, int n);

};
#pragma once

#include <string>
#include <vector>
#include "ImguiDefine.h"

using std::vector;
class Window;
class WindowObserver;

void SetOtherWindowName(Window* other, const char* text);
void SetFilePath(Window* other, std::string text);

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

	// 창 생성과 이름 같은 공통적인 작업을 모아둠
	void InitRender();
	void EndRender();

	virtual void Render() = 0;

	bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
	std::string GetFileDirectory();

	std::string ToString(std::wstring value);

	void SetObserver(WindowObserver* ob) { Observer = ob; };

protected:
	std::string BeginName;
	std::string WndName;

	ImVec2 WndPos;
	ImVec2 WndSize;
	WindowObserver* Observer;

	friend void SetOtherWindowName(Window* other, const char* text);
};





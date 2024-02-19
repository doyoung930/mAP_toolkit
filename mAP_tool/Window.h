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
	Window(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f));
	virtual ~Window() {}

	// 창 생성과 이름 같은 공통적인 작업을 모아둠
	void InitRender();
	void EndRender();
	virtual void ProcessAfterEndRender() {};

	virtual void Render() = 0;

	bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
	std::string GetFileDirectory();

	std::string ToString(std::wstring value);
	std::wstring ToWString(std::string value);

	void SetObserver(WindowObserver* ob) { Observer = ob; };
	void SetSelectIndex(int index);
	void SetCateArray(std::vector<std::string>* CateArray) { this->CateArray = CateArray; }

	ImVec2 GetWindowCenter(ImVec2 RenderObjectSize);

protected:
	std::string BeginName;
	std::string WndName;

	ImVec2 WndPos;
	ImVec2 WndSize;
	WindowObserver* Observer;

	ImVec4 WndBgColor;
	ImGuiStyle WndStyle;

	int CurrentSelectIndex;
	bool DiffCurrentIndex;

	bool ChangedFontSize;

	std::vector<std::string>* CateArray;

};





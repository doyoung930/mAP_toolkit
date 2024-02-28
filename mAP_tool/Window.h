#pragma once

#include <string>
#include <vector>
#include "ImguiDefine.h"

using std::vector;
class Window;
class WindowObserver;

class Window
{
public:
	// TODO: 빌더 디자인 패턴 사용해보자
	Window(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f));
	virtual ~Window() {}

	// 창 생성과 이름 같은 공통적인 작업을 모아둠
	void InitRender();
	void EndRender();

	virtual void Render() = 0;

	// 사진 Load, 현재 쓰지않음
	bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);

	// Window에서 제공해주는 디렉토리 경로 설정 창 Open
	std::string GetFileDirectory();

	// 간단한 한글 출력
	void RenderUnicode(std::string str);

	std::string ToString(std::wstring value);
	std::wstring ToWString(std::string value);

	void SetObserver(WindowObserver* ob) { Observer = ob; };
	void SetSelectIndex(int index);

	// 오브젝트를 윈도우의 중앙에 배치하기 위한 좌표
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
};





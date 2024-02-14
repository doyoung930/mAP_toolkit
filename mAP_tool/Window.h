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
	// TODO: ���� ������ ���� ����غ���
	Window(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
		:	BeginName(Beginname),
			WndName(Wndname),
			WndPos(Wndpos),
			WndSize(Wndsize),
			CurrentSelectIndex(-1)
	{}
	virtual ~Window() {}

	// â ������ �̸� ���� �������� �۾��� ��Ƶ�
	void InitRender();
	void EndRender();

	virtual void Render() = 0;

	bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
	std::string GetFileDirectory();

	std::string ToString(std::wstring value);

	void SetObserver(WindowObserver* ob) { Observer = ob; };
	void SetSelectIndex(int index);
	void SetCateArray(std::vector<std::string>* CateArray) { this->CateArray = CateArray; }

protected:
	std::string BeginName;
	std::string WndName;

	ImVec2 WndPos;
	ImVec2 WndSize;
	WindowObserver* Observer;

	int CurrentSelectIndex;
	bool DiffCurrentIndex;

	std::vector<std::string>* CateArray;
};





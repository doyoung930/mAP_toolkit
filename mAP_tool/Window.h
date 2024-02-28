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
	// TODO: ���� ������ ���� ����غ���
	Window(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor = ImVec4(0.f, 0.f, 0.f, .8f));
	virtual ~Window() {}

	// â ������ �̸� ���� �������� �۾��� ��Ƶ�
	void InitRender();
	void EndRender();

	virtual void Render() = 0;

	// ���� Load, ���� ��������
	bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);

	// Window���� �������ִ� ���丮 ��� ���� â Open
	std::string GetFileDirectory();

	// ������ �ѱ� ���
	void RenderUnicode(std::string str);

	std::string ToString(std::wstring value);
	std::wstring ToWString(std::string value);

	void SetObserver(WindowObserver* ob) { Observer = ob; };
	void SetSelectIndex(int index);

	// ������Ʈ�� �������� �߾ӿ� ��ġ�ϱ� ���� ��ǥ
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





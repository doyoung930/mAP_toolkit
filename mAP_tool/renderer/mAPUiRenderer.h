#pragma once

#include "renderer/Renderer.h"

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_win32.h"
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <GL/GL.h>
#include <tchar.h>

// Data stored per platform window
struct WGL_WindowData { HDC hDC; };

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class mAPUiRenderer : public Renderer
{
public:
	mAPUiRenderer() {}
	~mAPUiRenderer() {}

	void render();

	// Imgui 관련 코드
public:
	int Main();

	// Helper functions
	bool CreateDeviceWGL(HWND hWnd, WGL_WindowData* data);
	void CleanupDeviceWGL(HWND hWnd, WGL_WindowData* data);	
	
	// Win32 message handler
	// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
	// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
	// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
	// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	// Data
	static HGLRC            g_hRC;
	static WGL_WindowData   g_MainWindow;
	static int              g_Width;
	static int              g_Height;
};


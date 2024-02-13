#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <fstream>
#include <vector>

#include "imgui/imconfig.h"
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/imstb_rectpack.h"
#include "imgui/imstb_textedit.h"
#include "imgui/imstb_truetype.h"

// imgui_impl_win32.h 파일 정보
#ifndef IMGUI_DISABLE

IMGUI_IMPL_API bool     ImGui_ImplWin32_Init(void* hwnd);
IMGUI_IMPL_API bool     ImGui_ImplWin32_InitForOpenGL(void* hwnd);
IMGUI_IMPL_API void     ImGui_ImplWin32_Shutdown();
IMGUI_IMPL_API void     ImGui_ImplWin32_NewFrame();

#if 0
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
#endif
IMGUI_IMPL_API void     ImGui_ImplWin32_EnableDpiAwareness();
IMGUI_IMPL_API float    ImGui_ImplWin32_GetDpiScaleForHwnd(void* hwnd);       // HWND hwnd
IMGUI_IMPL_API float    ImGui_ImplWin32_GetDpiScaleForMonitor(void* monitor); // HMONITOR monitor

IMGUI_IMPL_API void     ImGui_ImplWin32_EnableAlphaCompositing(void* hwnd);   // HWND hwnd

#endif // #ifndef IMGUI_DISABLE

#define FONTSIZE 18.0f


using std::cout;
using std::endl;
using std::string;
using std::vector;
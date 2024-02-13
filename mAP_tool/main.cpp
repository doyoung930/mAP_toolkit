// Dear ImGui: standalone example application for Win32 + OpenGL 3

// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

// This is provided for completeness, however it is strongly recommended you use OpenGL with SDL or GLFW.

#pragma execution_character_set("utf-8")
#include "renderer/mAPUiRenderer.h"
// Main code
int main(int, char**)
{
    setlocale(LC_ALL, "");

    mAPUiRenderer* renderer = new mAPUiRenderer();

    return renderer->Main();
}

#include "Window.h"

void Window::Render()
{
    bool isOpen = true;

    ImGui::Begin(BeginName.c_str(), &isOpen, ImGuiWindowFlags_NoTitleBar);                          // Create a window called "Hello, world!" and append into it.
    ImGui::SetWindowPos(WndPos);
    ImGui::SetWindowSize(WndSize);

    ImGui::Text(WndName.c_str());

    ImGui::End();
}

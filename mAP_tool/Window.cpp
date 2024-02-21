#define STB_IMAGE_IMPLEMENTATION
#include "header.h"

#include "Window.h"
#include "imgui/stb_image.h"
#include <Windows.h>

#include <commdlg.h>

#include <iostream>
using std::cout;
using std::endl;

Window::Window(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor)
    : BeginName(Beginname),
    WndName(Wndname),
    WndPos(Wndpos),
    WndSize(Wndsize),
    CurrentSelectIndex(-1),
    ChangedFontSize(false),
    WndBgColor(BgColor)
{
}

void Window::InitRender()
{
    ImGuiWindowFlags window_flags = 0;
    bool isOpen = true;

    ImGuiStyle* style = &ImGui::GetStyle();
    ImVec4* colors = style->Colors;

    colors[ImGuiCol_WindowBg] = WndBgColor;

    window_flags |= ImGuiWindowFlags_NoTitleBar;
    window_flags |= ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoResize;

    ImGui::Begin(BeginName.c_str(), &isOpen, window_flags);                          // Create a window called "Hello, world!" and append into it.
    ImGui::SetWindowPos(WndPos);
    ImGui::SetWindowSize(WndSize);

    ImGui::Text(WndName.c_str());
}

void Window::EndRender()
{
    ImGui::End();

    if (ChangedFontSize)
    {
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.Fonts->Fonts[0]->FontSize = FONTSIZE;
        ChangedFontSize = false;
    }
}

bool Window::LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
{

    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
    {
        cout << "File Directory FAIL" << endl;
        return false;
    }

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}

#include <shlobj.h>
std::string Window::GetFileDirectory()
{
    TCHAR folderPath[MAX_PATH] = L"";

    BROWSEINFO bi = { 0 };
    bi.lpszTitle = L"���� ����";
    bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;

    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
    if (pidl != NULL)
    {
        SHGetPathFromIDList(pidl, folderPath);
        CoTaskMemFree(pidl);

        return ToString(folderPath);
    }

    return std::string("");
}

std::string Window::ToString(std::wstring value)
{
    std::string temp;
    temp.assign(value.begin(), value.end());
    return temp;
}

std::wstring Window::ToWString(std::string value)
{
    std::wstring temp;
    temp.assign(value.begin(), value.end());
    return temp;
}

void Window::SetSelectIndex(int index)
{
    if (index == CurrentSelectIndex)
    {
        DiffCurrentIndex = false;
    }
    else
    {
        DiffCurrentIndex = true;
        CurrentSelectIndex = index;
    }
}

ImVec2 Window::GetWindowCenter(ImVec2 RenderObjectSize)
{
    ImVec2 ReturnValue;
    ReturnValue.x = (WndSize.x - RenderObjectSize.x) / 2;
    ReturnValue.y = (WndSize.y - RenderObjectSize.y) / 2;
    return ReturnValue;
}


void Window::RenderUnicode(std::string str)
{
    if (str == "Uk") { ImGui::Text((const char*)u8"Uk"); }
    else if (str == "1") { ImGui::Text((const char*)u8"1"); }
    else if (str == "2") { ImGui::Text((const char*)u8"2"); }
    else if (str == "3") { ImGui::Text((const char*)u8"3"); }
    else if (str == "4") { ImGui::Text((const char*)u8"4"); }
    else if (str == "5") { ImGui::Text((const char*)u8"5"); }
    else if (str == "6") { ImGui::Text((const char*)u8"6"); }
    else if (str == "7") { ImGui::Text((const char*)u8"7"); }
    else if (str == "8") { ImGui::Text((const char*)u8"8"); }
    else if (str == "9") { ImGui::Text((const char*)u8"9"); }
    else if (str == "0") { ImGui::Text((const char*)u8"0"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "ȣ") { ImGui::Text((const char*)u8"ȣ"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "õ") { ImGui::Text((const char*)u8"õ"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��"); }
}
#define STB_IMAGE_IMPLEMENTATION
#include "header.h"

#include "Window.h"
#include "imgui/stb_image.h"
#include <Windows.h>

#include <commdlg.h>

#include <iostream>
using std::cout;
using std::endl;

void Window::InitRender()
{
    bool isOpen = true;

    ImGui::Begin(BeginName.c_str(), &isOpen, ImGuiWindowFlags_NoTitleBar);                          // Create a window called "Hello, world!" and append into it.
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
    bi.lpszTitle = L"폴더 선택";
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

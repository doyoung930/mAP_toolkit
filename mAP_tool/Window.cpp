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
    else if (str == "가") { ImGui::Text((const char*)u8"가"); }
    else if (str == "나") { ImGui::Text((const char*)u8"나"); }
    else if (str == "다") { ImGui::Text((const char*)u8"다"); }
    else if (str == "라") { ImGui::Text((const char*)u8"라"); }
    else if (str == "마") { ImGui::Text((const char*)u8"마"); }
    else if (str == "바") { ImGui::Text((const char*)u8"바"); }
    else if (str == "사") { ImGui::Text((const char*)u8"사"); }
    else if (str == "아") { ImGui::Text((const char*)u8"아"); }
    else if (str == "자") { ImGui::Text((const char*)u8"자"); }
    else if (str == "거") { ImGui::Text((const char*)u8"거"); }
    else if (str == "너") { ImGui::Text((const char*)u8"너"); }
    else if (str == "더") { ImGui::Text((const char*)u8"더"); }
    else if (str == "러") { ImGui::Text((const char*)u8"러"); }
    else if (str == "머") { ImGui::Text((const char*)u8"머"); }
    else if (str == "버") { ImGui::Text((const char*)u8"버"); }
    else if (str == "서") { ImGui::Text((const char*)u8"서"); }
    else if (str == "어") { ImGui::Text((const char*)u8"어"); }
    else if (str == "저") { ImGui::Text((const char*)u8"저"); }
    else if (str == "고") { ImGui::Text((const char*)u8"고"); }
    else if (str == "노") { ImGui::Text((const char*)u8"노"); }
    else if (str == "도") { ImGui::Text((const char*)u8"도"); }
    else if (str == "로") { ImGui::Text((const char*)u8"로"); }
    else if (str == "모") { ImGui::Text((const char*)u8"모"); }
    else if (str == "보") { ImGui::Text((const char*)u8"보"); }
    else if (str == "소") { ImGui::Text((const char*)u8"소"); }
    else if (str == "오") { ImGui::Text((const char*)u8"오"); }
    else if (str == "조") { ImGui::Text((const char*)u8"조"); }
    else if (str == "구") { ImGui::Text((const char*)u8"구"); }
    else if (str == "누") { ImGui::Text((const char*)u8"누"); }
    else if (str == "두") { ImGui::Text((const char*)u8"두"); }
    else if (str == "루") { ImGui::Text((const char*)u8"루"); }
    else if (str == "무") { ImGui::Text((const char*)u8"무"); }
    else if (str == "부") { ImGui::Text((const char*)u8"부"); }
    else if (str == "수") { ImGui::Text((const char*)u8"수"); }
    else if (str == "우") { ImGui::Text((const char*)u8"우"); }
    else if (str == "주") { ImGui::Text((const char*)u8"주"); }
    else if (str == "허") { ImGui::Text((const char*)u8"허"); }
    else if (str == "하") { ImGui::Text((const char*)u8"하"); }
    else if (str == "호") { ImGui::Text((const char*)u8"호"); }
    else if (str == "배") { ImGui::Text((const char*)u8"배"); }
    else if (str == "공") { ImGui::Text((const char*)u8"공"); }
    else if (str == "해") { ImGui::Text((const char*)u8"해"); }
    else if (str == "육") { ImGui::Text((const char*)u8"육"); }
    else if (str == "합") { ImGui::Text((const char*)u8"합"); }
    else if (str == "국") { ImGui::Text((const char*)u8"국"); }
    else if (str == "울") { ImGui::Text((const char*)u8"울"); }
    else if (str == "경") { ImGui::Text((const char*)u8"경"); }
    else if (str == "기") { ImGui::Text((const char*)u8"기"); }
    else if (str == "강") { ImGui::Text((const char*)u8"강"); }
    else if (str == "원") { ImGui::Text((const char*)u8"원"); }
    else if (str == "북") { ImGui::Text((const char*)u8"북"); }
    else if (str == "대") { ImGui::Text((const char*)u8"대"); }
    else if (str == "남") { ImGui::Text((const char*)u8"남"); }
    else if (str == "전") { ImGui::Text((const char*)u8"전"); }
    else if (str == "산") { ImGui::Text((const char*)u8"산"); }
    else if (str == "제") { ImGui::Text((const char*)u8"제"); }
    else if (str == "영") { ImGui::Text((const char*)u8"영"); }
    else if (str == "충") { ImGui::Text((const char*)u8"충"); }
    else if (str == "인") { ImGui::Text((const char*)u8"인"); }
    else if (str == "천") { ImGui::Text((const char*)u8"천"); }
    else if (str == "세") { ImGui::Text((const char*)u8"세"); }
    else if (str == "종") { ImGui::Text((const char*)u8"종"); }
}
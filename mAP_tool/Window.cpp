#define STB_IMAGE_IMPLEMENTATION
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
    //OPENFILENAME OFN;
    //TCHAR filePathName[100] = L"";
    //TCHAR lpstrFile[100] = L"";
    //static TCHAR filter[] = L"모든 파일\0*.*\0텍스트 파일\0*.txt\0fbx 파일\0*.fbx";

    //HWND hWnd = GetActiveWindow();

    //memset(&OFN, 0, sizeof(OPENFILENAME));
    //OFN.lStructSize = sizeof(OPENFILENAME);
    //OFN.hwndOwner = hWnd;
    //OFN.lpstrFilter = filter;
    //OFN.lpstrFile = lpstrFile;
    //OFN.nMaxFile = 100;
    //OFN.lpstrInitialDir = L".";

    //if (GetOpenFileName(&OFN) != 0)
    //{
    //    wsprintf(filePathName, L"%s 파일을 열겠습니까?", OFN.lpstrFile);
    //    MessageBox(hWnd, filePathName, L"열기 선택", MB_OK);

    //    std::string t = ToString(OFN.lpstrFile);

    //    return t;
    //}
    //return std::string("");
}

std::string Window::ToString(std::wstring value)
{
    std::string temp;
    temp.assign(value.begin(), value.end());
    return temp;
}

void ImageWindow::Render()
{
    //int my_image_width = 0;
    //int my_image_height = 0;
    //GLuint my_image_texture = 0;
    //bool ret = LoadTextureFromFile("C:\\Users\\user\\Desktop\\LPR vat\\aihub_lpr\\경기37바1383.jpg",
    //                                    &my_image_texture, &my_image_width, &my_image_height);
    //IM_ASSERT(ret);

    //ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
}

void ButtonWindow::Render()
{
    if (ImGui::Button("Directory"))
    {
        cout << "AAA" << endl;

        std::string FileDirectory;
        FileDirectory = GetFileDirectory();
        if (FileDirectory != "")
        {

        }

        // 디렉토리path에 있는 모든 파일 검사
        //for (const auto& file : directory_iterator(path)) cout << file.path() << endl;
    }
}

void ImageListWindow::Render()
{
    static int current_part_idx{ 0 };
    if(ImGui::BeginListBox("Draw List", ImVec2(300, 900)))
    {
        const char* items[] = { "AAAA",    "BBBB", "CCCC", "DDDD",  "EEEE", "FFFF",  "GGGG",  "HHHH", "IIII",   "JJJJ", "KKKK",
                                   "LLLLLLL", "MMMM", "NNNN", "OOOOO", "PPP",  "QQQQQ", "RRRRR", "SSSS", "TTTTTT", "UUU" };
        
        for (int n = 0; n < IM_ARRAYSIZE(items); ++n)
        {
            const bool is_selected = (current_part_idx == n);
            if (ImGui::Selectable(items[n], is_selected)) { current_part_idx = n; }

            // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
            if (is_selected) { ImGui::SetItemDefaultFocus(); }
        }
    }
    ImGui::EndListBox();
}

void AttributeWindow::Render()
{
}

void CategoriesWindow::Render()
{
}

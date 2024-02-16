#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#include "ImageListWindow.h"

// string 변환
#include <codecvt>

#include <filesystem>
namespace fs = std::filesystem;

void ImageListWindow::Render()
{
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    auto NowFont = io.Fonts->Fonts[0];
    NowFont->FontSize = 8.f;
    ChangedFontSize = true;
    if (CurrentSelectIndex != -1)
    {
        if (DiffCurrentIndex)
        {
            SetRenderText();
        }
    }

    //ImGui::SetWindowFontScale(1.2f);ImGui::CalcTextSize(IndexStr.c_str())
    auto CenterPos = GetWindowCenter(NowFont->CalcTextSizeA(NowFont->FontSize, FLT_MAX, 0.0f, (char*)IndexStr.c_str()));
    ImGui::SetCursorPosX(CenterPos.x);
    ImGui::SetCursorPosY(CenterPos.y);
    ImGui::Text((char*)IndexStr.c_str());
    //io.Fonts->Fonts[0]->FontSize = 18.f;

    //if (ImGui::BeginListBox("Draw List", ImVec2(300, 900)))
    //{
    //    for (int n = 0; n < ImageNames.size(); ++n)
    //    {
    //        const bool is_selected = (CurrentSelectIndex == n);
    //        if (ImGui::Selectable(ImageNames[n].c_str(), is_selected)) { CurrentSelectIndex = n; }
    //        // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
    //        if (is_selected) { ImGui::SetItemDefaultFocus(); }
    //    }
    //}
    //ImGui::EndListBox();
}

void ImageListWindow::LoadImageWithPath(std::string path)
{
    ImageNames.clear();

    FilePath = path;


    //// std::wstring_convert을 사용하여 std::wstring으로 변환
    //std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    //std::wstring utf16String = converter.from_bytes(path);
    //std::wstring WPath(path.begin(), path.end());

    for (const auto& entry : fs::directory_iterator(FilePath))
    {
        std::string filename;
        if (entry.path().extension() == ".jpg")
        {
            filename = entry.path().filename().string();
            ImageNames.emplace_back(filename);
        }
    }
}

void ImageListWindow::SetRenderText()
{
    IndexStr = ToWString((*CateArray)[CurrentSelectIndex]);
}

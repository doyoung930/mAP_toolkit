#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#include "ImageListWindow.h"

// string ��ȯ
#include <codecvt>

#include <filesystem>
namespace fs = std::filesystem;

void ImageListWindow::Render()
{
    if (CurrentSelectIndex == -1)
    {
        ImGui::Text("None");
        return;
    }

    if (DiffCurrentIndex)
    {
        SetRenderText();
    }

    ImGui::Text(IndexStr.c_str());

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


    //// std::wstring_convert�� ����Ͽ� std::wstring���� ��ȯ
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
    IndexStr = (*CateArray)[CurrentSelectIndex];
}

#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#include "DrawApWindow.h"
#include "GlobalVariable.h"

// string º¯È¯
#include <codecvt>

#include <filesystem>
namespace fs = std::filesystem;

void DrawApWindow::Render()
{
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    auto NowFont = io.Fonts->Fonts[0];
    NowFont->FontSize = 10.f;
    ChangedFontSize = true;
    if (CurrentSelectIndex != -1)
    {
        if (DiffCurrentIndex)
        {
            SetRenderText();
        }
        std::vector<float>& APArray = GlobalVariable::Instance()->GetApArray();
        std::string str = std::to_string(APArray[CurrentSelectIndex] * 100) + "%";

        auto CenterPos = GetWindowCenter(NowFont->CalcTextSizeA(NowFont->FontSize, FLT_MAX, 0.0f, (char*)str.c_str()));
        ImGui::SetCursorPosX(CenterPos.x - 50);
        ImGui::SetCursorPosY(CenterPos.y);

        ImGui::Text(str.c_str());
    }
}

void DrawApWindow::SetRenderText()
{
    std::vector<std::string>& CateArray = GlobalVariable::Instance()->GetCateArray();
    IndexStr = ToWString((CateArray)[CurrentSelectIndex]);
}

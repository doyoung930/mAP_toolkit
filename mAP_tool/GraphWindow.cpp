#include "GraphWindow.h"
#include "GlobalVariable.h"

#include <random>

GraphWindow::GraphWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor)
    : Window(Beginname, Wndname, Wndpos, Wndsize, BgColor)
{

}

void GraphWindow::Render()
{
    ImGuiStyle& style = ImGui::GetStyle();

    static int track_item = 50;
    static bool enable_track = true;
    static bool enable_extra_decorations = false;
    static float scroll_to_off_px = 0.0f;
    static float scroll_to_pos_px = 200.0f;

    float child_height = WndSize.y - 100;//ImGui::GetTextLineHeight() + style.ScrollbarSize + style.WindowPadding.y * 2.0f;
    ImGuiWindowFlags child_flags = ImGuiWindowFlags_HorizontalScrollbar | (enable_extra_decorations ? ImGuiWindowFlags_AlwaysVerticalScrollbar : 0);
    ImGuiID child_id = ImGui::GetID((void*)(intptr_t)0);
    bool child_is_visible = ImGui::BeginChild(child_id, ImVec2(-100, child_height), ImGuiChildFlags_Border, child_flags);

    // 받은 AP의 최댓값 구하기 <- 0 ~ 1 사이로 정해지나?

    // 최댓값을 기준으로 역정규화 하기
    int CanUseHeight = child_height - (ImGui::GetTextLineHeight() + style.ScrollbarSize + style.WindowPadding.y * 2.0f);
    
    std::vector<float>& APArray = GlobalVariable::Instance()->GetApArray();
    std::vector<std::string>& CateArray = GlobalVariable::Instance()->GetCateArray();

    //ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0, 0));
    for (int item = 0; item < CateArray.size(); item++)
    {
        if (item > 0)
            ImGui::SameLine();

        int ApPercent = APArray[item] * 100;
        std::string ApPercentStr = std::to_string(ApPercent) + "%";

        char ApStr[10];
        sprintf_s(ApStr, "%f", APArray[item]);

        float hue = item * 0.05f;
        ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(hue, 0.6f, 0.6f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(hue, 0.7f, 0.7f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(hue, 0.8f, 0.8f));


        ImGui::SetCursorPosY(CanUseHeight - (CanUseHeight * APArray[item]));

        ImGui::Button(ApPercentStr.c_str(), ImVec2(40.0f, CanUseHeight * APArray[item]));
        ImGui::PopStyleColor(3);
    }
    //ImGui::PopStyleVar();

    if (child_is_visible) // Avoid calling SetScrollHereY when running with culled items
    {
        ImGui::SetCursorPosY(child_height - (ImGui::GetTextLineHeight() + style.ScrollbarSize + style.WindowPadding.y * 2.0f));
        for (int item = 0; item < CateArray.size(); item++)
        {
            if (item > 0)
                ImGui::SameLine();

            std::string PrintText;
            if (item == 0)
                PrintText = "Uk";
            else
                PrintText = (CateArray)[item];
            TextCentered(PrintText, 40 + 8, item);
            RenderUnicode(PrintText);

            ImGui::SameLine();
            ImGui::Text("\t");
        }
    }

    float scroll_x = ImGui::GetScrollX();
    float scroll_max_x = ImGui::GetScrollMaxX();
    ImGui::EndChild();
    ImGui::SameLine();
    ImGui::Text("%s\n%.0f/%.0f", "Graph", scroll_x, scroll_max_x);
    ImGui::Spacing();
}

void GraphWindow::TextCentered(std::string text, int BoxSize, int n)
{
    auto windowWidth = BoxSize ;
    auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

    auto TextPos = (windowWidth - textWidth >= 0) ? windowWidth - textWidth : 0;

    auto CurrentPosX = ImGui::GetCursorPosX();

    ImGui::SetCursorPosX(windowWidth * n);
    ImGui::Text("|");
    ImGui::SameLine();
    ImGui::SetCursorPosX(windowWidth * n + (TextPos) * 0.5f);
    //ImGui::Text(text.c_str());
}
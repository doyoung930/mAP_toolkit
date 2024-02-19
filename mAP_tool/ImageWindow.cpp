#include "ImageWindow.h"

#include <random>

ImageWindow::ImageWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor)
    : Window(Beginname, Wndname, Wndpos, Wndsize, BgColor)
{
    std::uniform_real_distribution<float> uid(0.f, 1.f);
    std::random_device rd;

    APArray.reserve(75);
    for (int i = 0; i < 75; i++)
    {
        APArray.push_back(uid(rd));
    }
}

void ImageWindow::Render()
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

    // ���� AP�� �ִ� ���ϱ� <- 0 ~ 1 ���̷� ��������?

    // �ִ��� �������� ������ȭ �ϱ�
    int CanUseHeight = child_height - (ImGui::GetTextLineHeight() + style.ScrollbarSize + style.WindowPadding.y * 2.0f);
    

    // 
    for (int item = 0; item < CateArray->size(); item++)
    {
        if (item > 0)
            ImGui::SameLine();

        char ApStr[10];
        sprintf_s(ApStr, "%f", APArray[item]);

        float hue = item * 0.05f;
        ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(hue, 0.6f, 0.6f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(hue, 0.7f, 0.7f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(hue, 0.8f, 0.8f));


        ImGui::SetCursorPosY(CanUseHeight - (CanUseHeight * APArray[item]));

        ImGui::Button(ApStr, ImVec2(40.0f, CanUseHeight * APArray[item]));
        ImGui::PopStyleColor(3);
    }

    if (child_is_visible) // Avoid calling SetScrollHereY when running with culled items
    {
        ImGui::SetCursorPosY(child_height - (ImGui::GetTextLineHeight() + style.ScrollbarSize + style.WindowPadding.y * 2.0f));
        for (int item = 0; item < CateArray->size(); item++)
        {
            if (item > 0)
                ImGui::SameLine();
            //if (enable_track && item == track_item)
            //{
            //    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Item %d", item);
            //    ImGui::SetScrollHereX(0 * 0.25f); // 0.0f:left, 0.5f:center, 1.0f:right
            //}
            //else
            //{
            //}
            std::string PrintText = (*CateArray)[item];
            TextCentered(PrintText, 40);
            RenderUnicode(PrintText);
        }
    }

    float scroll_x = ImGui::GetScrollX();
    float scroll_max_x = ImGui::GetScrollMaxX();
    ImGui::EndChild();
    ImGui::SameLine();
    ImGui::Text("%s\n%.0f/%.0f", "Graph", scroll_x, scroll_max_x);
    ImGui::Spacing();
}

void ImageWindow::ProcessAfterEndRender()
{
}

void ImageWindow::TextCentered(std::string text, int BoxSize)
{
    auto windowWidth = BoxSize;
    auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

    auto TextPos = (windowWidth - textWidth >= 0) ? windowWidth - textWidth : 0;

    auto CurrentPosX = ImGui::GetCursorPosX();
    ImGui::SetCursorPosX(CurrentPosX + (TextPos) * 0.5f);
    //ImGui::Text(text.c_str());
}

void ImageWindow::RenderUnicode(std::string str)
{
    if (str == "Unknown") { ImGui::Text((const char*)u8"Unknown"); }
    else if (str == "1")  { ImGui::Text((const char*)u8"1"); }
    else if (str == "2")  { ImGui::Text((const char*)u8"2"); }
    else if (str == "3")  { ImGui::Text((const char*)u8"3"); }
    else if (str == "4")  { ImGui::Text((const char*)u8"4"); }
    else if (str == "5")  { ImGui::Text((const char*)u8"5"); }
    else if (str == "6")  { ImGui::Text((const char*)u8"6"); }
    else if (str == "7")  { ImGui::Text((const char*)u8"7"); }
    else if (str == "8")  { ImGui::Text((const char*)u8"8"); }
    else if (str == "9")  { ImGui::Text((const char*)u8"9"); }
    else if (str == "0")  { ImGui::Text((const char*)u8"0"); }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "ȣ") { ImGui::Text((const char*)u8"ȣ");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "õ") { ImGui::Text((const char*)u8"õ");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }
    else if (str == "��") { ImGui::Text((const char*)u8"��");  }


    ImGui::SameLine();
    ImGui::Text("\t");
}
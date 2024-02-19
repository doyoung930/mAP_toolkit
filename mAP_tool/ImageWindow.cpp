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

    // 받은 AP의 최댓값 구하기 <- 0 ~ 1 사이로 정해지나?

    // 최댓값을 기준으로 역정규화 하기
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
    else if (str == "가") { ImGui::Text((const char*)u8"가");  }
    else if (str == "나") { ImGui::Text((const char*)u8"나");  }
    else if (str == "다") { ImGui::Text((const char*)u8"다");  }
    else if (str == "라") { ImGui::Text((const char*)u8"라");  }
    else if (str == "마") { ImGui::Text((const char*)u8"마");  }
    else if (str == "바") { ImGui::Text((const char*)u8"바");  }
    else if (str == "사") { ImGui::Text((const char*)u8"사");  }
    else if (str == "아") { ImGui::Text((const char*)u8"아");  }
    else if (str == "자") { ImGui::Text((const char*)u8"자");  }
    else if (str == "거") { ImGui::Text((const char*)u8"거");  }
    else if (str == "너") { ImGui::Text((const char*)u8"너");  }
    else if (str == "더") { ImGui::Text((const char*)u8"더");  }
    else if (str == "러") { ImGui::Text((const char*)u8"러");  }
    else if (str == "머") { ImGui::Text((const char*)u8"머");  }
    else if (str == "버") { ImGui::Text((const char*)u8"버");  }
    else if (str == "서") { ImGui::Text((const char*)u8"서");  }
    else if (str == "어") { ImGui::Text((const char*)u8"어");  }
    else if (str == "저") { ImGui::Text((const char*)u8"저");  }
    else if (str == "고") { ImGui::Text((const char*)u8"고");  }
    else if (str == "노") { ImGui::Text((const char*)u8"노");  }
    else if (str == "도") { ImGui::Text((const char*)u8"도");  }
    else if (str == "로") { ImGui::Text((const char*)u8"로");  }
    else if (str == "모") { ImGui::Text((const char*)u8"모");  }
    else if (str == "보") { ImGui::Text((const char*)u8"보");  }
    else if (str == "소") { ImGui::Text((const char*)u8"소");  }
    else if (str == "오") { ImGui::Text((const char*)u8"오");  }
    else if (str == "조") { ImGui::Text((const char*)u8"조");  }
    else if (str == "구") { ImGui::Text((const char*)u8"구");  }
    else if (str == "누") { ImGui::Text((const char*)u8"누");  }
    else if (str == "두") { ImGui::Text((const char*)u8"두");  }
    else if (str == "루") { ImGui::Text((const char*)u8"루");  }
    else if (str == "무") { ImGui::Text((const char*)u8"무");  }
    else if (str == "부") { ImGui::Text((const char*)u8"부");  }
    else if (str == "수") { ImGui::Text((const char*)u8"수");  }
    else if (str == "우") { ImGui::Text((const char*)u8"우");  }
    else if (str == "주") { ImGui::Text((const char*)u8"주");  }
    else if (str == "허") { ImGui::Text((const char*)u8"허");  }
    else if (str == "하") { ImGui::Text((const char*)u8"하");  }
    else if (str == "호") { ImGui::Text((const char*)u8"호");  }
    else if (str == "배") { ImGui::Text((const char*)u8"배");  }
    else if (str == "공") { ImGui::Text((const char*)u8"공");  }
    else if (str == "해") { ImGui::Text((const char*)u8"해");  }
    else if (str == "육") { ImGui::Text((const char*)u8"육");  }
    else if (str == "합") { ImGui::Text((const char*)u8"합");  }
    else if (str == "국") { ImGui::Text((const char*)u8"국");  }
    else if (str == "울") { ImGui::Text((const char*)u8"울");  }
    else if (str == "경") { ImGui::Text((const char*)u8"경");  }
    else if (str == "기") { ImGui::Text((const char*)u8"기");  }
    else if (str == "강") { ImGui::Text((const char*)u8"강");  }
    else if (str == "원") { ImGui::Text((const char*)u8"원");  }
    else if (str == "북") { ImGui::Text((const char*)u8"북");  }
    else if (str == "대") { ImGui::Text((const char*)u8"대");  }
    else if (str == "남") { ImGui::Text((const char*)u8"남");  }
    else if (str == "전") { ImGui::Text((const char*)u8"전");  }
    else if (str == "산") { ImGui::Text((const char*)u8"산");  }
    else if (str == "제") { ImGui::Text((const char*)u8"제");  }
    else if (str == "영") { ImGui::Text((const char*)u8"영");  }
    else if (str == "충") { ImGui::Text((const char*)u8"충");  }
    else if (str == "인") { ImGui::Text((const char*)u8"인");  }
    else if (str == "천") { ImGui::Text((const char*)u8"천");  }
    else if (str == "세") { ImGui::Text((const char*)u8"세");  }
    else if (str == "종") { ImGui::Text((const char*)u8"종");  }


    ImGui::SameLine();
    ImGui::Text("\t");
}
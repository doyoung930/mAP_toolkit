#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

#include "CategoriesWindow.h"
#include "WindowObserver.h"
#include "GlobalVariable.h"

CategoriesWindow::CategoriesWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize, ImVec4 BgColor)
	: Window(Beginname, Wndname, Wndpos, Wndsize, BgColor)
{
}

void CategoriesWindow::Render()
{
    std::vector<std::string>& CateArray = GlobalVariable::Instance()->GetCateArray();

    if (ImGui::BeginListBox("##Box", ImVec2(WndSize.x - 50, WndSize.y - 100)))
    {
        for (int n = 0; n < CateArray.size(); ++n)
        {
            RenderUnicode((CateArray)[n], n);
        }
        ImGui::EndListBox();
    }
    Observer->OnNotify(MAINGRAPHWINDOW, EventEnum::SET_CURRENT_SELECT, &CurrentSelectIndex);
    Observer->OnNotify(MAINDRAWAPWINDOW, EventEnum::SET_CURRENT_SELECT, &CurrentSelectIndex);
}

void CategoriesWindow::RenderUnicode(std::string str, int n)
{
    const bool is_selected = (CurrentSelectIndex == n);
    if (str == "Unknown")    {if (ImGui::Selectable((const char*)u8"Unknown", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "1")     {if (ImGui::Selectable((const char*)u8"1", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "2")     {if (ImGui::Selectable((const char*)u8"2", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "3")     {if (ImGui::Selectable((const char*)u8"3", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "4")     {if (ImGui::Selectable((const char*)u8"4", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "5")     {if (ImGui::Selectable((const char*)u8"5", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "6")     {if (ImGui::Selectable((const char*)u8"6", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "7")     {if (ImGui::Selectable((const char*)u8"7", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "8")     {if (ImGui::Selectable((const char*)u8"8", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "9")     {if (ImGui::Selectable((const char*)u8"9", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "0")     {if (ImGui::Selectable((const char*)u8"0", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "가")    {if (ImGui::Selectable((const char*)u8"가", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "나")    {if (ImGui::Selectable((const char*)u8"나", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "다")    {if (ImGui::Selectable((const char*)u8"다", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "라")    {if (ImGui::Selectable((const char*)u8"라", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "마")    {if (ImGui::Selectable((const char*)u8"마", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "바")    {if (ImGui::Selectable((const char*)u8"바", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "사")    {if (ImGui::Selectable((const char*)u8"사", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "아")    {if (ImGui::Selectable((const char*)u8"아", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "자")    {if (ImGui::Selectable((const char*)u8"자", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "거")    {if (ImGui::Selectable((const char*)u8"거", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "너")    {if (ImGui::Selectable((const char*)u8"너", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "더")    {if (ImGui::Selectable((const char*)u8"더", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "러")    {if (ImGui::Selectable((const char*)u8"러", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "머")    {if (ImGui::Selectable((const char*)u8"머", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "버")    {if (ImGui::Selectable((const char*)u8"버", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "서")    {if (ImGui::Selectable((const char*)u8"서", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "어")    {if (ImGui::Selectable((const char*)u8"어", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "저")    {if (ImGui::Selectable((const char*)u8"저", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "고")    {if (ImGui::Selectable((const char*)u8"고", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "노")    {if (ImGui::Selectable((const char*)u8"노", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "도")    {if (ImGui::Selectable((const char*)u8"도", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "로")    {if (ImGui::Selectable((const char*)u8"로", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "모")    {if (ImGui::Selectable((const char*)u8"모", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "보")    {if (ImGui::Selectable((const char*)u8"보", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "소")    {if (ImGui::Selectable((const char*)u8"소", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "오")    {if (ImGui::Selectable((const char*)u8"오", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "조")    {if (ImGui::Selectable((const char*)u8"조", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "구")    {if (ImGui::Selectable((const char*)u8"구", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "누")    {if (ImGui::Selectable((const char*)u8"누", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "두")    {if (ImGui::Selectable((const char*)u8"두", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "루")    {if (ImGui::Selectable((const char*)u8"루", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "무")    {if (ImGui::Selectable((const char*)u8"무", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "부")    {if (ImGui::Selectable((const char*)u8"부", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "수")    {if (ImGui::Selectable((const char*)u8"수", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "우")    {if (ImGui::Selectable((const char*)u8"우", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "주")    {if (ImGui::Selectable((const char*)u8"주", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "허")    {if (ImGui::Selectable((const char*)u8"허", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "하")    {if (ImGui::Selectable((const char*)u8"하", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "호")    {if (ImGui::Selectable((const char*)u8"호", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "배")    {if (ImGui::Selectable((const char*)u8"배", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "공")    {if (ImGui::Selectable((const char*)u8"공", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "해")    {if (ImGui::Selectable((const char*)u8"해", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "육")    {if (ImGui::Selectable((const char*)u8"육", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "합")    {if (ImGui::Selectable((const char*)u8"합", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "국")    {if (ImGui::Selectable((const char*)u8"국", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "울")    {if (ImGui::Selectable((const char*)u8"울", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "경")    {if (ImGui::Selectable((const char*)u8"경", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "기")    {if (ImGui::Selectable((const char*)u8"기", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "강")    {if (ImGui::Selectable((const char*)u8"강", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "원")    {if (ImGui::Selectable((const char*)u8"원", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "북")    {if (ImGui::Selectable((const char*)u8"북", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "대")    {if (ImGui::Selectable((const char*)u8"대", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "남")    {if (ImGui::Selectable((const char*)u8"남", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "전")    {if (ImGui::Selectable((const char*)u8"전", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "산")    {if (ImGui::Selectable((const char*)u8"산", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "제")    {if (ImGui::Selectable((const char*)u8"제", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "영")    {if (ImGui::Selectable((const char*)u8"영", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "충")    {if (ImGui::Selectable((const char*)u8"충", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "인")    {if (ImGui::Selectable((const char*)u8"인", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "천")    {if (ImGui::Selectable((const char*)u8"천", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "세")    {if (ImGui::Selectable((const char*)u8"세", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "종")    {if (ImGui::Selectable((const char*)u8"종", is_selected)) { CurrentSelectIndex = n; }}

    // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
    if (is_selected) { ImGui::SetItemDefaultFocus(); }
}
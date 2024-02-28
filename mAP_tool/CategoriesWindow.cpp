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
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "ȣ")    {if (ImGui::Selectable((const char*)u8"ȣ", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "õ")    {if (ImGui::Selectable((const char*)u8"õ", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}
    else if (str == "��")    {if (ImGui::Selectable((const char*)u8"��", is_selected)) { CurrentSelectIndex = n; }}

    // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
    if (is_selected) { ImGui::SetItemDefaultFocus(); }
}
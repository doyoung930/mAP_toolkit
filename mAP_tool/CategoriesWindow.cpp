#define _CRT_SECURE_NO_WARNINGS
#include "CategoriesWindow.h"
#include "iostream"

CategoriesWindow::CategoriesWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
	: Window(Beginname, Wndname, Wndpos, Wndsize)
{
    Init();
}

void CategoriesWindow::Render()
{
    if (ImGui::BeginListBox("Draw List", ImVec2(300, 9000)))
    {
            if (ImGui::Selectable((const char*)u8"��", true)) { CurrentSelectIndex = 0; }
        for (int n = 1; n < CateArray.size(); ++n)
        {
            RenderUnicode(CateArray[n], n);
        }
    }
    ImGui::EndListBox();
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

void CategoriesWindow::Init()
{
    CateArray.clear();

    CateArray.push_back("Unknown");
    CateArray.push_back("1");
    CateArray.push_back("2");
    CateArray.push_back("3");
    CateArray.push_back("4");
    CateArray.push_back("5");
    CateArray.push_back("6");
    CateArray.push_back("7");
    CateArray.push_back("8");
    CateArray.push_back("9");
    CateArray.push_back("0");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("ȣ");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("õ");
    CateArray.push_back("��");
    CateArray.push_back("��");
}


#include "header.h"

#include "ButtonWindow.h"
#include "WindowObserver.h"
#include "GlobalVariable.h"
#include "inference/Inference.h"

#include <iostream>
using std::cout;
using std::endl;

ButtonWindow::ButtonWindow(std::string Beginname, std::string Wndname, ImVec2 Wndpos, ImVec2 Wndsize)
    : Window(Beginname, Wndname, Wndpos, Wndsize)
{
    //Observer->OnNotify(MAINATTRIBUTEWINDOW, EventEnum::SET_IOU, &items[0][0]);
}

void ButtonWindow::Render()
{
    static bool IsFirst = true;
    if (IsFirst)
    {
        Observer->OnNotify(MAINATTRIBUTEWINDOW, EventEnum::SET_IOU, &items[0][0]);
        IsFirst = false;
    }


    ImGuiStyle& style = ImGui::GetStyle();

    if (ImGui::Button("Directory"))
    {
        cout << "AAA" << endl;

        FilePath = GetFileDirectory();
        if (FilePath != "")
        {
            //SetFilePath()
            Observer->OnNotify(MAINIMAGELISTWINDOW, EventEnum::SET_DIRECTORY_PATH, &FilePath[0]);

            auto instance = GlobalVariable::Instance();
            instance->GetInference()->run(FilePath);
        }

    }

    auto ButtonHeight = ImGui::GetTextLineHeight() + style.FramePadding.y * 2;
    auto TextHeight = ImGui::CalcTextSize("IOU").y;

    ImGui::SetCursorPosY(WndSize.y - (ButtonHeight + TextHeight * 2) * 2);
    static float f0 = 0.001f;
    ImGui::Text("IOU");

    static char str[128] = "";
    //ImGui::InputTextWithHint("##LABEL", "Float", str, IM_ARRAYSIZE(str));

    static int item_current_idx = 0; // Here we store our selection data as an index.
    // Pass in the preview value visible before opening the combo (it could technically be different contents or not pulled from items[])
    const string combo_preview_value = items[item_current_idx];
    if (ImGui::BeginCombo("##LABEL", combo_preview_value.c_str(), ImGuiComboFlags_WidthFitPreview))
    {
        for (int n = 0; n < IM_ARRAYSIZE(items); n++)
        {
            const bool is_selected = (item_current_idx == n);
            if (ImGui::Selectable(items[n].c_str(), is_selected))
                item_current_idx = n;

            // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
            if (is_selected)
                ImGui::SetItemDefaultFocus();
        }

        if (combo_preview_value != items[item_current_idx])
        {
            //cout << "Changed" << endl;
            Observer->OnNotify(MAINATTRIBUTEWINDOW, EventEnum::SET_IOU, &items[item_current_idx][0]);
        }

        ImGui::EndCombo();
    }

    //if (ImGui::Button("IOU Set"))
    //{
    //    try {
    //        static float value = std::stof(str);
    //        std::cout << "Converted value: " << value << std::endl;

    //        Observer->OnNotify(MAINATTRIBUTEWINDOW, EventEnum::SET_IOU, &value);
    //    }
    //    catch (const std::invalid_argument& e) {
    //        std::cerr << "Invalid argument: " << e.what() << std::endl;
    //        std::cerr << "소숫점을 입력해주세요." << std::endl;
    //    }
    //    catch (const std::out_of_range& e) {
    //        std::cerr << "Out of range: " << e.what() << std::endl;
    //    }

    //    ZeroMemory(str, sizeof(char) * 128);
    //}
}
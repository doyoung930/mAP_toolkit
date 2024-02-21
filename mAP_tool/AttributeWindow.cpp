#include "AttributeWindow.h"
#include <string>

#define STRING(num) #num

void AttributeWindow::Render()
{
	auto TextSize = ImGui::CalcTextSize(IOUStr.c_str());
	ImGui::SetCursorPos(ImVec2(WndSize.x - TextSize.x - 15, WndSize.y - TextSize.y - 15));
	ImGui::Text(IOUStr.c_str());


}
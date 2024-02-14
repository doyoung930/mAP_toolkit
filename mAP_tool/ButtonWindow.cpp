#include "header.h"

#include "ButtonWindow.h"
#include "WindowObserver.h"

#include <iostream>
using std::cout;
using std::endl;

void ButtonWindow::Render()
{
    if (ImGui::Button("Directory"))
    {
        cout << "AAA" << endl;

        FilePath = GetFileDirectory();
        if (FilePath != "")
        {
            //SetFilePath()
            Observer->OnNotify(MAINIMAGELISTWINDOW, EventEnum::SET_DIRECTORY_PATH, &FilePath[0]);
        }

        // ���丮path�� �ִ� ��� ���� �˻�
        //for (const auto& file : directory_iterator(path)) cout << file.path() << endl;
    }
}
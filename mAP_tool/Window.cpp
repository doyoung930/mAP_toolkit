#define STB_IMAGE_IMPLEMENTATION
#include "Window.h"
#include "imgui/stb_image.h"
#include <Windows.h>

#include <iostream>
using std::cout;
using std::endl;

void Window::Render(bool IsCalledSuper)
{
    bool isOpen = true;

    ImGui::Begin(BeginName.c_str(), &isOpen, ImGuiWindowFlags_NoTitleBar);                          // Create a window called "Hello, world!" and append into it.
    ImGui::SetWindowPos(WndPos);
    ImGui::SetWindowSize(WndSize);

    ImGui::Text(WndName.c_str());

    if(!IsCalledSuper)
        ImGui::End();
}

bool Window::LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
{

    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
    {
        cout << "File Directory FAIL" << endl;
        return false;
    }

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}

void ImageWindow::Render(bool IsCalledSuper)
{
    __super::Render(true);

    int my_image_width = 0;
    int my_image_height = 0;
    GLuint my_image_texture = 0;
    bool ret = LoadTextureFromFile("C:\\Users\\user\\Desktop\\LPR vat\\aihub_lpr\\°æ±â37¹Ù1383.jpg",
                                        &my_image_texture, &my_image_width, &my_image_height);
    IM_ASSERT(ret);

    ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));

    ImGui::End();
}

void ButtonWindow::Render(bool IsCalledSuper)
{
    __super::Render(true);

    if (ImGui::Button("Directory"))
    {
    }


    ImGui::End();
}

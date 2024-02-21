#include "header.h"

#include "mAPUiRenderer.h"
#include "Window.h"

#include "ImageWindow.h"
#include "ButtonWindow.h"
#include "ImageListWindow.h"
#include "AttributeWindow.h"
#include "CategoriesWindow.h"

#include "WindowObserver.h"

HGLRC          mAPUiRenderer::g_hRC;
WGL_WindowData mAPUiRenderer::g_MainWindow;
int            mAPUiRenderer::g_Width;
int            mAPUiRenderer::g_Height;

using std::string;

mAPUiRenderer::mAPUiRenderer()
{
    WndObserver = WindowObserver::Instance();

    Windows.insert(std::pair(MAINIMAGEWINDOW, new ImageWindow(string("Image"), string("Graph"), ImVec2(100, 0), ImVec2(1200, 900), ImVec4(.8f, 0.2f, 0.2f, .8f))));
    Windows[MAINBUTTONWINDOW] = new ButtonWindow(string("Button List"), string("Buttons"), ImVec2(0, 0), ImVec2(100, 900));
    //TODO: 크기가 15 넘어감 왜?
    Windows[MAINIMAGELISTWINDOW] = new ImageListWindow(string("Image List"), string("Select AP"), ImVec2(1300, 0), ImVec2(285, 250));
    Windows[MAINATTRIBUTEWINDOW] = new AttributeWindow(string("Attribute"), string("mAP / IOU"), ImVec2(1300, 250), ImVec2(285, 250));
    Windows[MAINCATEGORYWINDOW] = new CategoriesWindow(string("Category"), string("Class"), ImVec2(1300, 500), ImVec2(285, 400));

    for (auto& w : Windows)
    {
        w.second->SetObserver(WndObserver);
    }

}

mAPUiRenderer::~mAPUiRenderer()
{
    for (auto& w : Windows)
    {
        delete w.second;
    }
}

void mAPUiRenderer::render()
{
	ImGui::Begin("Test");
}

int mAPUiRenderer::Main()
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEXW wc = { sizeof(wc), CS_OWNDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"ImGui Example", nullptr };
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"Dear ImGui Win32+OpenGL3 Example", WS_OVERLAPPEDWINDOW, 100, 100, 1600, 900, nullptr, nullptr, wc.hInstance, nullptr);

    // Initialize OpenGL
    if (!CreateDeviceWGL(hwnd, &g_MainWindow))
    {
        CleanupDeviceWGL(hwnd, &g_MainWindow);
        ::DestroyWindow(hwnd);
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }
    wglMakeCurrent(g_MainWindow.hDC, g_hRC);

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;   // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;    // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_InitForOpenGL(hwnd);
    ImGui_ImplOpenGL3_Init();

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return a nullptr. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    io.Fonts->AddFontFromFileTTF("Font/HakgyoansimMonggeulmonggeulR.ttf", FONTSIZE, nullptr, io.Fonts->GetGlyphRangesKorean());
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != nullptr);

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    bool done = false;
    while (!done)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        Init();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        // if (show_demo_window)
        //     ImGui::ShowDemoWindow(&show_demo_window);

        // 2.
        for (const auto& w : Windows)
        {
            w.second->InitRender();             // Being() Function
            w.second->Render();                 // Main Render
            w.second->EndRender();              // End() Function
            w.second->ProcessAfterEndRender();  // Reset Font or Bg Color
        }

        // Process Event Queue Notify
        ProcessNotify();

        // 3. Show another simple window.
        //if (show_another_window)
        //{
        //    ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        //    ImGui::Text("Hello from another window!");
        //    if (ImGui::Button("Close Me"))
        //        show_another_window = false;
        //    ImGui::End();
        //}

        // Rendering
        ImGui::Render();
        glViewport(0, 0, g_Width, g_Height);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Present
        ::SwapBuffers(g_MainWindow.hDC);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceWGL(hwnd, &g_MainWindow);
    wglDeleteContext(g_hRC);
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);

    return 0;
}

void mAPUiRenderer::Init()
{
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

//void mAPUiRenderer::RenderImageWnd()
//{
//    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
//    static float f = 0.0f;
//    static int counter = 0;
//    bool isOpen = true;
//
//    ImGui::Begin("Image", &isOpen, ImGuiWindowFlags_NoTitleBar);                          // Create a window called "Hello, world!" and append into it.
//    ImGui::SetWindowPos(ImVec2(100, 0));
//    ImGui::SetWindowSize(ImVec2(1200, 900));
//
//    ImGui::Text("Image");               // Display some text (you can use a format strings too)
//    //ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
//    //ImGui::Checkbox("Another Window", &show_another_window);
//    //
//    //ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
//    //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
//    //
//    //if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
//    //    counter++;
//    //ImGui::SameLine();
//    //ImGui::Text("counter = %d", counter);
//    //
//    //ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
//    ImGui::End();
//}

bool mAPUiRenderer::CreateDeviceWGL(HWND hWnd, WGL_WindowData* data)
{
    HDC hDc = ::GetDC(hWnd);
    PIXELFORMATDESCRIPTOR pfd = { 0 };
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;

    const int pf = ::ChoosePixelFormat(hDc, &pfd);
    if (pf == 0)
        return false;
    if (::SetPixelFormat(hDc, pf, &pfd) == FALSE)
        return false;
    ::ReleaseDC(hWnd, hDc);

    data->hDC = ::GetDC(hWnd);
    if (!g_hRC)
        g_hRC = wglCreateContext(data->hDC);
    return true;
}

void mAPUiRenderer::CleanupDeviceWGL(HWND hWnd, WGL_WindowData* data)
{
    wglMakeCurrent(nullptr, nullptr);
    ::ReleaseDC(hWnd, data->hDC);
}

LRESULT __stdcall mAPUiRenderer::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam != SIZE_MINIMIZED)
        {
            g_Width = LOWORD(lParam);
            g_Height = HIWORD(lParam);
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}

void mAPUiRenderer::ProcessNotify()
{
    std::queue<Event>& ObQueue = WndObserver->GetQueue();

    while (!ObQueue.empty())
    {
        Event e = ObQueue.front();
        ObQueue.pop();

        switch (e.evet)
        {
        case EventEnum::SET_DIRECTORY_PATH:
        {
            ImageListWindow* ILWd = dynamic_cast<ImageListWindow*>(Windows[e.Serial]);
            string path((char*)e.mess);
            ILWd->LoadImageWithPath(path);  //*(std::string*)e.mess
        }
            break;
        case EventEnum::SET_CURRENT_SELECT:
            Windows[e.Serial]->SetSelectIndex(*(int*)e.mess);
            break;
        case EventEnum::SET_IOU:
        {
            AttributeWindow* ATWd = static_cast<AttributeWindow*>(Windows[e.Serial]);
            string iou((char*)e.mess);
            ATWd->SetIOU(iou);
        }
            break;
        default:
            break;
        }
    }
}

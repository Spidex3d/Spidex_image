#include "MainScreen.h"
#include <imgui\ImGuiAF.h>
#include "../headers/GlobalVars.h"

MainScreen* MainScreen::Instance()
{
	static MainScreen* screen = new MainScreen;
	return screen;
}

void MainScreen::Initialize(GLFWwindow* window)
{
}

void MainScreen::SetUpImGui(GLFWwindow* window)
{
    // Make sue to include all imgui files in the project
    //ImGui set up
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    //io.KeyMap[ImGuiKey_H] = GLFW_KEY_HOME;
    ImGui::StyleColorsDark();

	ImGui_ImplOpenGL3_Init("#version 460");
    ImGui_ImplGlfw_InitForOpenGL(window, true);


    // Make it possible to use Icons From FontAwesome5
    ImFontConfig fontconfig;
    fontconfig.MergeMode = true;
    fontconfig.PixelSnapH = true;
    static const ImWchar ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };

    // set the fonts
    fontconfig.GlyphOffset = ImVec2(0.0f, 1.0f);
    //io.Fonts->AddFontFromFileTTF(ROBOTO_REG_PATH, FONT_SIZE); // sandard font type
    io.Fonts->AddFontFromFileTTF(FONT_PATH_MAIN, FONT_SIZE); // comic sans font type
    io.Fonts->AddFontFromFileTTF(FA_SOLID_PATH, FONT_SIZE, &fontconfig, ranges);
}

void MainScreen::NewImGuiFrame(GLFWwindow* window)
{

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

}

void MainScreen::MainDockSpace(GLFWwindow* window)
{
}

void MainScreen::MainSceneWindow(GLFWwindow* window)
{
}

void MainScreen::MainMenuBar(GLFWwindow* window)
{
    // This is my main window menu
    ImGui::BeginMainMenuBar();
    if (ImGui::BeginMenu("File"))
    {
        if (ImGui::MenuItem("New Image"))
        {

        }
        if (ImGui::MenuItem("Open Image"))
        {

        }
        ImGui::Separator();
        if (ImGui::MenuItem(ICON_FA_SAVE" Save Image"))
        {

        }
        if (ImGui::MenuItem("Save As Image"))
        {

        }
        ImGui::Separator();
        if (ImGui::MenuItem(ICON_FA_SIGN_OUT_ALT" Exit"))
        {
            glfwSetWindowShouldClose(window, true);
        }
        ImGui::EndMenu();

    }
    if (ImGui::BeginMenu("Edit"))
    {
        if (ImGui::MenuItem("Cut"))
        {

        }
        if (ImGui::MenuItem("Copy"))
        {

        }
        if (ImGui::MenuItem("Paste"))
        {

        }
        ImGui::Separator();
        if (ImGui::MenuItem("Wire Frame"))
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
        if (ImGui::MenuItem("Wire Frame off"))
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Settings"))
    {
        if (ImGui::MenuItem(ICON_FA_COGS" Open Settings"))
        {
           // show_settings_window = true; // show settings window

        }

        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Tools"))
    {
        if (ImGui::MenuItem("Open Tool Box"))
        {

        }

        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("View"))
    {
        if (ImGui::MenuItem("Hi"))
        {

        }
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Effects"))
    {
        if (ImGui::MenuItem("Testing"))
        {


        }
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Adjust"))
    {
        if (ImGui::MenuItem("Ground Plane"))
        {

        }

        if (ImGui::MenuItem("Water Plane"))
        {

        }

        if (ImGui::MenuItem("Cube"))
        {

        }
        ;
        if (ImGui::MenuItem("Plane"))
        {

        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("About"))
    {
        if (ImGui::MenuItem("About Screen"))
        {
            //show_about_window = true; // show About Window
        }

        if (ImGui::MenuItem("Help"))
        {

        }
        ImGui::Separator();
        if (ImGui::MenuItem("Window Opacity on"))
        {
            glfwSetWindowOpacity(window, 0.6f);
        }
        if (ImGui::MenuItem("Window Opacity off"))
        {
            glfwSetWindowOpacity(window, 1.0f);
        }
        ImGui::Separator();
        if (ImGui::MenuItem("Visit Web Site"))
        {

        }
        ImGui::EndMenu();
    }
    

    ImGui::EndMainMenuBar();

	
}

void MainScreen::WinInit(GLFWwindow* window)
{
	MainScreen::NewImGuiFrame(window);
	ImGui::NewFrame();
	MainScreen::MainMenuBar(window);
}

void MainScreen::RenderImGui(GLFWwindow* window)
{
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        GLFWwindow* backup_context = glfwGetCurrentContext(); // Get the current window conttext
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_context);
    }
}



void MainScreen::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
}

void MainScreen::BgColor(float BgCol[4])
{
	 glClearColor(BgCol[0], BgCol[1], BgCol[2], BgCol[3]);
}

#include "headers/App.h"
#include "windows/WindowsManager.h"
#include "windows/MainScreen.h"
#include "tools/ImageLab.h"
#include "headers/GlobalVars.h"
#include "headers\EditorInput.h"

App::App()
{
}

App::~App()
{
}

App* App::Instance()
{
	App* mainApp = new App;
	return mainApp;
}

void App::Initialize(GLFWwindow* window)
{
}

void App::RunApp()
{
	WindowsManager windowManager(SCR_WIDTH, SCR_HEIGHT, SCR_TITLE);
	if (!windowManager.GLFWInitialize()) {
		return;
	}
	else
	{
		MainScreen::Instance()->Initialize(windowManager.GetWindow());
		
		MainScreen::Instance()->SetUpImGui(windowManager.GetWindow());
	}

	while (AppIsRunning)
	{
		if (glfwWindowShouldClose(windowManager.GetWindow())) { AppIsRunning = false; }
		
		EditorInput::Instance()->processInput(windowManager.GetWindow()); // Process input for the editor

		MainScreen::Instance()->WinInit(windowManager.GetWindow());		// New Frame, Menu and DockSpace Init

		ImageLab::Instance()->GUI_Init(windowManager.GetWindow());		// window GUI Init
		ImageLab::Instance()->MainImageWindow(windowManager.GetWindow()); // Main Image Window

		MainScreen::Instance()->BgColor(BgCol);
		MainScreen::Instance()->ClearScreen();

		MainScreen::Instance()->RenderImGui(windowManager.GetWindow()); // Render ImGui

		glfwSwapBuffers(windowManager.GetWindow());
		glfwPollEvents();
	}
	App::AppCleanup();
}

void App::AppCleanup()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}

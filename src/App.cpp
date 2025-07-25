#include "headers/App.h"
#include "windows/WindowsManager.h"
#include "windows/MainScreen.h"
#include "tools/ImageLab.h"
#include "headers/GlobalVars.h"

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
		// load stuff in here
		MainScreen::Instance()->SetUpImGui(windowManager.GetWindow());
	}

	while (AppIsRunning)
	{
		if (glfwWindowShouldClose(windowManager.GetWindow())) { AppIsRunning = false; }
		
		MainScreen::Instance()->WinInit(windowManager.GetWindow());

		ImageLab::Instance()->File_location(windowManager.GetWindow());

		MainScreen::Instance()->BgColor(BgCol);
		MainScreen::Instance()->ClearScreen();

		MainScreen::Instance()->RenderImGui(windowManager.GetWindow());

		glfwSwapBuffers(windowManager.GetWindow());
		glfwPollEvents();
	}

}

void App::AppCleanup()
{
}

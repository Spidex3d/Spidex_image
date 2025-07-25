#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui\ImGuiAF.h>
#include <imgui\imgui.h>
#include <imgui\imgui_impl_glfw.h>
#include <imgui\imgui_impl_opengl3.h>

class MainScreen
{
public:
	static MainScreen* Instance();
	void Initialize(GLFWwindow* window);

	void SetUpImGui(GLFWwindow* window);      // imgui set up
	void NewImGuiFrame(GLFWwindow* window);   // imgui new frame
	void MainDockSpace(GLFWwindow* window);   // add docking
	void MainSceneWindow(GLFWwindow* window); // the main scene window
	void MainMenuBar(GLFWwindow* window);     // main menu bar

	void WinInit(GLFWwindow* window);

	void RenderImGui(GLFWwindow* window);  // imgui main render

	void ClearScreen();

	void BgColor(float BgCol[4]);

private:
	GLFWwindow* window;

	
	
};


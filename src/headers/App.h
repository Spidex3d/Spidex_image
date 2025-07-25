#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class App
{
public:
	App();
	~App();
	static App* Instance();
	
	void Initialize(GLFWwindow* window);
	void RunApp();
	
	void AppCleanup();

private:
	GLFWwindow* window;
	

	bool AppIsRunning = true;
	
};


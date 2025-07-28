#include "headers/EditorInput.h"
#include "headers/GlobalVars.h"

EditorInput* EditorInput::Instance()
{
	
		static EditorInput instance;
		return &instance;
	
}

void EditorInput::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);


	
}

#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class EditorInput
{
public:
	EditorInput() = default;
	~EditorInput() = default;
	// Singleton pattern
	static EditorInput* Instance();
	
	// Process input for the editor
	void processInput(GLFWwindow* window);

};


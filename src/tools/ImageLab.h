#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// this will contain all the image lab tools
// like the windows / toolbars for image processing, filters, etc.
class ImageLab
{
public:
	ImageLab() = default;
	~ImageLab() = default;
	static ImageLab* Instance();
	void Initialize(GLFWwindow* window);

	void MainImageWindow(GLFWwindow* window); // the main scene window
	void File_location(GLFWwindow* window);
	void Image_Navigation(GLFWwindow* window);
	void Color_palette(GLFWwindow* window);
	void Layer_Manager(GLFWwindow* window);
	
	void GUI_Init(GLFWwindow* window);		// Initialize ImGui or any other GUI framework here
	
private:
	GLFWwindow* window;

	// Add any other member variables or methods needed for the ImageLab functionality
};


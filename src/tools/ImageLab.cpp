#include "ImageLab.h"
#include <imgui\ImGuiAF.h>
#include <imgui\imgui.h>


ImageLab* ImageLab::Instance()
{
	static ImageLab* imagelab = new ImageLab;
	return imagelab;
}

void ImageLab::Initialize(GLFWwindow* window)
{
}

void ImageLab::File_location(GLFWwindow* window)
{
	ImGui::Begin("File Location");
	ImGui::Text("File Location: %s", "C:/path/to/image.png"); // Example file location
	ImGui::End(); // Close the window
}

void ImageLab::Image_Navigation(GLFWwindow* window)
{
}

void ImageLab::Color_palette(GLFWwindow* window)
{
}

void ImageLab::Layer_Manager(GLFWwindow* window)
{
}

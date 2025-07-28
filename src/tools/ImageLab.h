#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "../headers/GlobalVars.h"

// this will contain all the image lab tools
// like the windows / toolbars for image processing, filters, etc.
struct ImageTab {
	std::string filePath;
	GLuint imageTabID;
	int width, height;
	// Add any other info you need
};
struct FolderImage {
	GLuint imageID	; // Texture ID for the folder image
	std::string folderPath; // folder path
	std::vector<ImageTab> images;
};


class ImageLab
{
public:
	std::vector<FolderImage> folderImages; // holds all images in a folder
	std::vector<ImageTab> openImages; // holdes image info & tab info
	
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

	unsigned int LoadImagesFromFolder(const std::string& folderPath); // get all images from a folder
	unsigned int loadSaveImage(const std::string& imagePath, int& width, int& height);
private:
	GLFWwindow* window;
	unsigned char* imgData = nullptr; // Placeholder for image data, can be used to store image pixel data
	int imgSize = 256; // Default size for the image, can be adjusted as needed
	unsigned int img_Image = 0;
	bool imageLoaded = false;

	// Add any other member variables or methods needed for the ImageLab functionality
};


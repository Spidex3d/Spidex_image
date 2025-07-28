#define STB_IMAGE_IMPLEMENTATION
#include "ImageLab.h"
#include <imgui\ImGuiAF.h>
#include <imgui\imgui.h>
#include <stb/stb_image.h>
#include <filesystem>
#include "../windows/spx_FileDialog.h"

namespace fs = std::filesystem;

// Forward declaration
unsigned int loadSaveImage(const std::string& imagePath);
unsigned int LoadImagesFromFolder(const std::string& folderPath);

ImageLab* ImageLab::Instance()
{
	static ImageLab* imagelab = new ImageLab;
	return imagelab;
}

void ImageLab::Initialize(GLFWwindow* window)
{
}

void ImageLab::MainImageWindow(GLFWwindow* window)
{
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(12, 12));
    ImGui::Begin("Main scene");

    // ##
    const float window_width = ImGui::GetContentRegionAvail().x;
    const float window_height = ImGui::GetContentRegionAvail().y;

    //Rescale_frambuffer(window_width, window_height);
    glViewport(0, 0, window_width, window_height);

    ImVec2 pos = ImGui::GetCursorScreenPos();

    // ImGui::GetWindowDrawList()->AddImage((void*)main_scene_texture_id, ImVec2(pos.x, pos.y),
       //  ImVec2(pos.x + window_width, pos.y + window_height), ImVec2(0, 1), ImVec2(1, 0));
     // Detect right-click for popup menu 
    if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Right))
    {
        ImGui::OpenPopup("RightClickMenu");
    }
    // Create the right-click popup menu 
    if (ImGui::BeginPopup("RightClickMenu"))
    {

        if (ImGui::BeginMenu("Edit")) {

            if (ImGui::MenuItem("Cut")) {
                // set ShouldAddObjModel to true then add obj file to the tree
                //ShouldAddObjModel = true;
                //dialogType = false;   // sets is textured or obj file for the opendialog box

            }
            if (ImGui::MenuItem("Copy")) {

                //ShouldAddEditMesh = true;
                //dialogType = false;   // sets is textured or obj file for the opendialog box

            }
            if (ImGui::MenuItem("Paste")) {
                // set ShouldAddCube to true then add cube to the tree
               // ShouldAddCube = true;
               // dialogType = true;   // sets dialogType is textured or obj file for the opendialog box

            }
            if (ImGui::MenuItem("Duplicate")) {
                // set ShouldAddPlane to true then add plane to the tree
               // ShouldAddPlane = true;
                //dialogType = true;
            }



            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("View")) {
            if (ImGui::MenuItem("Test")) {
                //ShouldAddSunLight = true;
                //LightSelector = LIGHT_SUN;
            }
            if (ImGui::MenuItem("Test")) {
                //ShouldAddPointLight = true;
                //LightSelector = LIGHT_POINT;
            }
            if (ImGui::MenuItem("Test")) {
                //ShouldAddSpotLight = true;
                //LightSelector = LIGHT_SPOT;
            }


            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Ajust")) {
            if (ImGui::MenuItem("Test")) { // This is the main terrain
                //ShouldAddTerrain = true;
            }
            if (ImGui::MenuItem("Test")) {}
            if (ImGui::MenuItem("Test")) {  // This is the floor
                //ShouldAddFloor = true;
            }

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Effects")) {
            if (ImGui::MenuItem("Test")) { // This is the main terrain
                //ShouldAddSkyBox = true;

            }
            if (ImGui::MenuItem("Test")) {
                // ShouldAddSkyHem = true;
            }
            if (ImGui::MenuItem("Test")) {  // This is the floor
                // ShouldAddSkyHDIR = true;
            }

            ImGui::EndMenu();
        }

        ImGui::EndPopup();
    }


    //#####
    static int imgmapW = 0, imgmapH = 0;

    // Load OpenGL Image (for display)
    if (img_Image == 0) {
        img_Image = loadSaveImage("images/Brick_s.jpg", imgmapW, imgmapH);

        // Only add once!
        if (openImages.empty()) {
            openImages.push_back({ "images/Brick_s.jpg", img_Image, imgmapW, imgmapH });
        }
    }
    ImGui::BeginChild("TabBarChild", ImVec2(0, 524), true,
        ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_AlwaysVerticalScrollbar);
    {
        if (ImGui::BeginTabBar("MainImageWindowTabBar")) {
            for (size_t i = 0; i < openImages.size(); ++i) {
                auto& img = openImages[i];
                if (ImGui::BeginTabItem(img.filePath.c_str())) {
                    float childWidth = ImGui::GetWindowSize().x;
                    float imageWidth = (float)img.width;
                    float centerPos = (childWidth - imageWidth) * 0.5f;
                    if (centerPos > 0)
                        ImGui::SetCursorPosX(centerPos);

                    ImGui::Image((void*)(intptr_t)img.imageTabID, ImVec2(img.width, img.height));
                    ImGui::EndTabItem();
                }
            }

        }
            ImGui::EndTabBar();

        ImGui::EndChild();

    }
	
    ImGui::Text("Right-click for popup Menu.");
    ImGui::End();
    ImGui::PopStyleVar();
}




void ImageLab::File_location(GLFWwindow* window)
{
	ImGui::Begin("File Location");
	ImGui::Text(ICON_FA_FOLDER " File Location C:/path/to/image.png"); // Example file location
	ImGui::End(); // Close the window
}

void ImageLab::Image_Navigation(GLFWwindow* window)
{
    
    ImGui::Begin("Image Navigation");
    ImGui::TextColored(COLOR_LIGHTBLUE, ICON_FA_IMAGE " Available Images");

    if (!imageLoaded) {
        LoadImagesFromFolder("images");
        imageLoaded = true;
    }
    int imageCount = 0;
    for (const auto& folder : folderImages) {
        imageCount += folder.images.size();
    }

    int columns = imageCount;
    int count = 0;
    ImGui::BeginChild("ImageGrid", ImVec2(0, 100), true, ImGuiWindowFlags_HorizontalScrollbar); // scrollable

    for (const auto& folder : folderImages) {
        for (const auto& tex : folder.images) {
            ImGui::PushID(tex.filePath.c_str());
            if (ImGui::ImageButton((void*)(intptr_t)tex.imageTabID, ImVec2(64, 64))) {
                // Add to openImages if not already open
                bool alreadyOpen = false;
                for (const auto& openTab : openImages) {
                    if (openTab.filePath == tex.filePath) {
                        alreadyOpen = true;
                        break;
                    }
                }
                if (!alreadyOpen) {
                    openImages.push_back(tex);
                }
            }
            ImGui::PopID();

            if (++count % columns != 0) ImGui::SameLine();
        }
    }
   
    ImGui::EndChild();
    ImGui::End();
}


void ImageLab::Color_palette(GLFWwindow* window)
{
}

void ImageLab::Layer_Manager(GLFWwindow* window)
{
}

void ImageLab::GUI_Init(GLFWwindow* window)
{
	ImageLab::File_location(window);
	ImageLab::Image_Navigation(window);
}

unsigned int ImageLab::LoadImagesFromFolder(const std::string& folderPath)
{
    FolderImage folderImg;
    folderImg.folderPath = folderPath;

    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            std::string ext = entry.path().extension().string();
            if (ext == ".png" || ext == ".jpg" || ext == ".bmp") {
                int width = 0, height = 0;
                GLuint id = loadSaveImage(entry.path().string(), width, height);
                folderImg.images.push_back({ entry.path().string(), id, width, height });
            }
        }
    }

    folderImages.push_back(folderImg);
    return static_cast<unsigned int>(folderImg.images.size());
}
unsigned int ImageLab::loadSaveImage(const std::string& imagePath, int& width, int& height)
{
    unsigned int imageID;
    glGenTextures(1, &imageID);

    int nrComponents;
    unsigned char* data = stbi_load(imagePath.c_str(), &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format = (nrComponents == 1) ? GL_RED :
            (nrComponents == 3) ? GL_RGB :
            (nrComponents == 4) ? GL_RGBA : GL_RGB;

        glBindTexture(GL_TEXTURE_2D, imageID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(data);
    }
    else {
        std::cout << "Texture failed to load: " << imagePath << std::endl;
        stbi_image_free(data);
    }

    return imageID;
}



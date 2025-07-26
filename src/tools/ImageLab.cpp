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

    /* float relativeX;
     float relativeY;*/

     // ##### Mouse picking
    if (ImGui::IsMouseClicked(ImGuiMouseButton_Left))
    {
        /* ImVec2 mousePos = ImGui::GetMousePos();
         ImVec2 windowPos = ImGui::GetWindowPos();

         relativeX = mousePos.x - windowPos.x;
         relativeY = mousePos.y - windowPos.y;

         std::cout << "The mouse x (relative): " << relativeX << " The mouse y (relative): " << relativeY << std::endl;*/

         // this needs to go off and find the object we just clicked
        //SelectedObject = true;
    }
    //#####

    ImGui::Text("Right-click for popup Menu.");
    ImGui::End();
    ImGui::PopStyleVar();
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

void ImageLab::GUI_Init(GLFWwindow* window)
{
	ImageLab::File_location(window);
}

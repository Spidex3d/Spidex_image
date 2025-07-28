#pragma once
#include <windows.h>
#include <shobjidl.h> // For IFileDialog
#include <string>
#include <vector>

class spx_PickFolder
{

public:
    static std::string selectedFolder;
    static std::string spx_Folder(HWND owner = nullptr);
    

};


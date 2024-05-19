#include "entrypoint.h"
#include "launch.h"

#include "windows/win32_min.h"

#include <Shlwapi.h>

int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nShowCmd)
{
    WCHAR path[MAX_PATH];  // Buffer to store the module's file path
    HMODULE h_module = GetModuleHandleW(NULL);  // Get the handle to the current module

    // Retrieve the full path of the executable
    if (GetModuleFileNameW(h_module, path, MAX_PATH) > 0)
    {
        PathRemoveFileSpecW(path);  // Remove the file name, leaving the directory path
        SetCurrentDirectoryW(path);  // Set the current directory to the directory of the executable
    }

    // Launch the application using the entry point provided by dyro::entry()
    return dyro::launch(dyro::entry());
}

int main()
{
    HINSTANCE hInstance = GetModuleHandle(NULL);  // Get the handle to the current module instance
    HINSTANCE hPrevInstance = NULL;  // Previous instance is not used, so set to NULL
    PWSTR lpCmdLine = GetCommandLineW();  // Get the command-line string
    s32 nCmdShow = SW_SHOWDEFAULT;  // Set the default show command

    // Call the wWinMain function with the necessary parameters
    return wWinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}
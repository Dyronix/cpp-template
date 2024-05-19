#include "entrypoint.h"
#include "launch.h"

#include "windows/win32_min.h"

#include <Shlwapi.h>

int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nShowCmd)
{
    WCHAR path[MAX_PATH];
    HMODULE h_module = GetModuleHandleW(NULL);
    if (GetModuleFileNameW(h_module, path, MAX_PATH) > 0)
    {
        PathRemoveFileSpecW(path);
        SetCurrentDirectoryW(path);
    }

    return dyro::launch(dyro::entry());
}

int main()
{
    HINSTANCE histance = GetModuleHandle(NULL);
    HINSTANCE hprevinstance = NULL;
    PWSTR pcmdline = GetCommandLineW();
    s32 ncmdshow = SW_SHOWDEFAULT;

    return wWinMain(histance, hprevinstance, pcmdline, ncmdshow);
}
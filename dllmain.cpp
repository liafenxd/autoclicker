#include <iostream>
#include <Windows.h>
#include <string>
#include <cctype>

#include "clicker.h"

// initialize
void initialize()
{
    // initialize
    system("color 0a");
    system("title AutoClicker Console Window");
    std::cout << "AutoClicker (1.0.0) - Console Window" << std::endl << std::endl;

    // sleep and clear
    Sleep(1000);
    system("color 0f");
}

// load function
DWORD WINAPI load(HMODULE hModule)
{
    // message box load
    MessageBox(0, L"AutoClicker (1.0.0) has successfully injected.\nLoading Console Window...", L"Success", MB_ICONINFORMATION | MB_OK);

    // open window
    FILE* file;
    if (!AllocConsole())
    {
        // print error
        MessageBox(0, L"Console window failed to load.", L"Error", MB_ICONERROR | MB_OK);
        return NULL;
    }

    freopen_s(&file, "CONOUT$", "w", stdout);
    freopen_s(&file, "CONOUT$", "w", stderr);
    freopen_s(&file, "CONIN$", "r", stdin);
    std::cout.clear();
    std::clog.clear();
    std::cerr.clear();
    std::cin.clear();

    // initialize
    initialize();
    system("cls");

    // get keys
    int keys[] = { VK_LBUTTON, MOUSEEVENTF_LEFTUP, MOUSEEVENTF_LEFTUP };

    // create clicker class
    clicker clicker(10, 10, "Left", 'Q', 'Z', keys);
    clicker.set_cps();
    clicker.set_button();
    clicker.set_toggle_on();
    clicker.set_toggle_off();

    // print settings
    clicker.print_settings();

    // infinite loop
    while (true)
    {
        // toggle on
        if (GetAsyncKeyState(clicker.get_toggle_on()))
        {
            // set toggle and change color
            clicker.set_toggle(true);
            system("color 0a");
        }

        // toggle off
        if (GetAsyncKeyState(clicker.get_toggle_off()) && !GetAsyncKeyState(VK_CONTROL))
        {
            // set toggle and change color
            clicker.set_toggle(false);
            system("color 0f");
        }
        // self destruct
        else if (GetAsyncKeyState(clicker.get_toggle_off()) && GetAsyncKeyState(VK_CONTROL))
        {
            // self destruct & break
            clicker.self_destruct();
            break;
        }

        // if toggled
        if (clicker.is_toggled())
        {
            // filter out automated clicks
            if (GetAsyncKeyState(clicker.keys[0]) && !clicker.is_holding())
                clicker.set_holding(true);

            if (!GetAsyncKeyState(clicker.keys[0]) && clicker.is_holding())
                clicker.set_holding(false);

            // check if holding down
            if (clicker.is_holding())
            {
                // click
                clicker.click();

                // sleep for delay
                Sleep(1000 / clicker.get_random_cps());
            }
        }
    }

    // close file
    fclose(file);

    // free console
    FreeConsole();

    // end thread
    FreeLibraryAndExitThread(hModule, 0);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    // switch call
    switch (ul_reason_for_call)
    {
        // on attach
        case DLL_PROCESS_ATTACH:
            // load
            CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)load, hModule, 0, nullptr));
        case DLL_PROCESS_DETACH:
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}


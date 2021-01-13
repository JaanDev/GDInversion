#include "pch.h"
#include <cocos2d.h>
#include "minhook/include/MinHook.h"
#include "PlayerObject.h"
#include "MenuOptions.h"
#include "GameManager.h"

// My thread
DWORD __declspec(dllexport) WINAPI ZZZZZZZZZZZZZZZZZ(void* hModule) {
    // Init MinHook
    MH_Initialize();

    // Hooking
    GameManager::mem_init();
    MenuOptions::mem_init();
    PlayerObject::mem_init();

    // Enable all hooks
    MH_EnableHook(MH_ALL_HOOKS);

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0x1000, ZZZZZZZZZZZZZZZZZ, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
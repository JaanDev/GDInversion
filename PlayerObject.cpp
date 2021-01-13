#include "pch.h"
#include "PlayerObject.h"
#include "GameManager.h"

bool __fastcall PlayerObject::pushButtonHook(void* self, int edx, void* PlayerButton) {
    void* gm = GameManager::getSharedState();

    if (!GameManager::getGameVariable(gm, "enable-inversion-mod"))
        return PlayerObject::pushButton(self, PlayerButton);
    else
        return PlayerObject::releaseButton(self, PlayerButton);
}

bool __fastcall PlayerObject::releaseButtonHook(void* self, int edx, void* PlayerButton) {
    void* gm = GameManager::getSharedState();

    if (!GameManager::getGameVariable(gm, "enable-inversion-mod"))
        return PlayerObject::releaseButton(self, PlayerButton);
    else
        return PlayerObject::pushButton(self, PlayerButton);
}

void PlayerObject::mem_init()
{
    // Hooks
    size_t base = reinterpret_cast<size_t>(GetModuleHandle(0));

    MH_CreateHook(
        (PVOID)(base + 0x1F4E40),
        PlayerObject::pushButtonHook,
        (LPVOID*)&PlayerObject::pushButton
    );

    MH_CreateHook(
        (PVOID)(base + 0x1F4F70),
        PlayerObject::releaseButtonHook,
        (LPVOID*)&PlayerObject::releaseButton
    );
}
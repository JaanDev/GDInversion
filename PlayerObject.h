#pragma once
#include <cocos2d.h>
#include "minhook/include/MinHook.h"

using namespace cocos2d;

namespace PlayerObject {
	// Original functions
	inline bool(__thiscall* pushButton)(void* self, void* PlayerButton);
	inline bool(__thiscall* releaseButton)(void* self, void* PlayerButton);

	// Hook functions
	bool __fastcall pushButtonHook(void* self, int edx, void* PlayerButton);
	bool __fastcall releaseButtonHook(void* self, int edx, void* PlayerButton);

	// Hooks init function
	void mem_init();
}
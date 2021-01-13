#pragma once
#include <Windows.h>

namespace GameManager {
	inline void* (__cdecl* getSharedState)();
	inline bool(__thiscall* getGameVariable)(void* self, const char* key);
	void mem_init();
}
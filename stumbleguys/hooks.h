#pragma once
#include "offsets.h"

bool(__fastcall* hasEmote_Orig)(DWORD*, const char*, DWORD*);
bool __stdcall hasEmote_Hook(DWORD* __this, const char* emoteID, DWORD* method)
{
	printf("hasEmote replaced with hook\n");
	return true;
}

bool(__fastcall* hasSkin_Orig)(DWORD*, const char*, DWORD*);
bool __stdcall hasSkin_Hook(DWORD* __this, const char* skinID, DWORD* method)
{
	printf("hasSkin replaced with hook\n");
	return true;
}

bool(__fastcall* hasAnimation_Orig)(DWORD*, const char*, DWORD*);
bool __stdcall hasAnimation_Hook(DWORD* __this, const char* animationID, DWORD* method)
{
	printf("hasAnimation replaced with hook\n");
	return true;
}

bool(__fastcall* HasFootstep_Orig)(DWORD*, const char*, DWORD*);
bool __stdcall HasFootstep_Hook(DWORD* __this, const char* footstepID, DWORD* method)
{
	printf("HasFootstep replaced with hook\n");
	return true;
}

void unlockEmotes()
{
	MH_CreateHook(reinterpret_cast<LPVOID*>(gameAssembly + hasEmote), &hasEmote_Hook, (LPVOID*)hasEmote_Orig);
	MH_EnableHook(reinterpret_cast<LPVOID*>(gameAssembly + hasEmote));
}

void unlockSkins()
{
	MH_CreateHook(reinterpret_cast<LPVOID*>(gameAssembly + hasSkin), &hasSkin_Hook, (LPVOID*)hasSkin_Orig);
	MH_EnableHook(reinterpret_cast<LPVOID*>(gameAssembly + hasSkin));
}

void unlockAnimations()
{
	MH_CreateHook(reinterpret_cast<LPVOID*>(gameAssembly + hasAnimation), &hasAnimation_Hook, (LPVOID*)hasAnimation_Orig);
	MH_EnableHook(reinterpret_cast<LPVOID*>(gameAssembly + hasAnimation));
}

void unlockFootsteps()
{
	MH_CreateHook(reinterpret_cast<LPVOID*>(gameAssembly + HasFootstep), &HasFootstep_Hook, (LPVOID*)HasFootstep_Orig);
	MH_EnableHook(reinterpret_cast<LPVOID*>(gameAssembly + HasFootstep));
}
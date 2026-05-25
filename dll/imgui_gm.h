#pragma once
#include <stddef.h>
#include "Extension_Interface.h"
#include "YYRValue.h"

#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_gm.h"

// Modifiers for brief (see Wrapper.js)
#define GMDEFAULT(...) /**/
#define GMPASSTHROUGH(...) /**/
#define GMHIDDEN(...) /**/
#define GMPREPEND(...) /**/
#define GMAPPEND(...) /**/
#define GMOVERRIDE(...) /**/
#define GMRETURN(...) /**/
#define GMRETURNS(...) /**/
#define GMHINT(...) /**/
#ifdef OS_Windows
#define GMEXPORT __declspec(dllexport)
#elif OS_Linux
#define GMEXPORT __attribute__((visibility("default")))
#elif OS_Mac
#define GMEXPORT extern "C"
#endif

#define GMFUNC(name) GMEXPORT void name(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)

// Interface
#define ShowError(...) YYError("[ImGui_GM] An error has occured:\n- %s\n", __VA_ARGS__)
#define WriteLog(...) DebugConsoleOutput("[ImGui_GM] %s\n", __VA_ARGS__)

// Helpers
static __forceinline ImVec4 GMCOLOR_TO(int col, float alpha) {
	float r = (float)(col & 0xFF) / 0xFF;
	float g = (float)((col >> 8) & 0xFF) / 0xFF;
	float b = (float)((col >> 16) & 0xFF) / 0xFF;
	return ImVec4(r, g, b, alpha);
}

static __forceinline double GMCOLOR_FROM(ImVec4 col) {
	int r = (int)(col.x * 0xFF);
	int g = (int)(col.y * 0xFF);
	int b = (int)(col.z * 0xFF);
	int alpha = (int)(col.w * 0xFF);
	return r | (g << 8) | (b << 16) | (alpha << 24);
}

extern int g_KeepAlive;
extern int g_CommandBuffer;
extern int g_FontBuffer;
extern bool g_UpdateFont;

extern RValue g_Copy;
template<typename T> static __forceinline T* YYGetArray(RValue* arg, int ind, int len) {
	RValue* arr = &arg[ind];
	T* val = new T[len];
	for (int i = 0; i < len; i++) {
		GET_RValue(&g_Copy, arr, NULL, i);
		val[i] = g_Copy.val;
	}
	return val;
}
template<typename T> static __forceinline void YYSetArray(RValue* arg, T* arr, int len) {
	for (int i = 0; i < len; i++) {
		g_Copy.kind = VALUE_REAL;
		g_Copy.val = arr[i];
		SET_RValue(arg, &g_Copy, NULL, i);
	}
	return;
}

enum TextureType : char {
	TextureType_Raw = 0,
	TextureType_Sprite = 1 << 0,
	TextureType_Surface = 1 << 1,
	TextureType_Font = 1 << 2
};

static __forceinline ImTextureRef GetTexture(unsigned int id, unsigned int subimg, TextureType type=TextureType_Raw) {
	// Format:
	// u64: 00000000000000000000000000000000 0000000000000000 0000
	//      ^ subimg                         ^ id             ^ type
	return ImTextureRef(
		(subimg << 20) | (id << 4) | type
	);
}
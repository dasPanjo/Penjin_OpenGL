#pragma once
#include <SDL.h>
#include "Vector2.h"
namespace Penjin
{
	class Input
	{
	public:
		static void OnKeyDown(SDL_Keycode keyCode);
		static void OnKeyUp(SDL_Keycode keyCode);

		static bool IsKeyPressed(SDL_Keycode keyCode);
		static bool IsKeyDown(SDL_Keycode keyCode);

		static Vector2 mousePos;
		static Vector2 mouseSpeed;
	private:
		static int keys[256];
		static bool IsInRange(SDL_Keycode keyCode) { return keyCode >= 0 && keyCode <= 255; }
	};
}


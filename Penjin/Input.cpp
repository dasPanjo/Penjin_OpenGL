#include "Input.h"

namespace Penjin {
	int Input::keys[256];
	Vector2 Input::mousePos;
	Vector2 Input::mouseSpeed;

	void Input::OnKeyDown(SDL_Keycode keyCode)
	{
		if (!IsInRange(keyCode)) return;
		keys[keyCode] = 1;
	}

	void Input::OnKeyUp(SDL_Keycode keyCode)
	{
		if (!IsInRange(keyCode)) return;
		keys[keyCode] = 0;
	}

	bool Input::IsKeyPressed(SDL_Keycode keyCode)
	{
		if (!IsInRange(keyCode)) return false;
		return keys[keyCode] == 1;
	}

	bool Input::IsKeyDown(SDL_Keycode keyCode)
	{
		if (!IsInRange(keyCode)) return false;
		return keys[keyCode] != 0;
	}

}

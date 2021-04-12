#pragma once
#include "Component.h"
#include "GameObject.h"

namespace Penjin
{
	class GameComponent
		: public Component
	{
	public:
		GameComponent();

	private:
		GameObject* gameObject;
	};
}


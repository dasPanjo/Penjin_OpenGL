#include "Component.h"

namespace Penjin
{
	Component::Component()
		:gameObject(nullptr)
	{
	}
	void Component::SetGameObject(GameObject* gameObject)
	{
		this->gameObject = gameObject;
	}
}

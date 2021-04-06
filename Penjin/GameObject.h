#pragma once
#include <string>
#include <vector>
#include "Transform.h"
#include "Component.h"

namespace Penjin {
	class GameObject
	{
	public:
		std::string name;
		Transform transform;
		int tag = 0;

		GameObject();
		GameObject(std::string name);
		virtual ~GameObject();

		virtual void Start();
		virtual void Update();

		virtual void AddComponent(Component* component);
		virtual void RemoveComponent(Component* component);
	private:
		std::vector<Component*> components;
	};
}


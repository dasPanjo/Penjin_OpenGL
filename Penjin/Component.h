#pragma once
#include "Log.h"
namespace Penjin {
	class GameObject;
	class Component
	{
	public:
		Component();

		virtual void Start() {}
		virtual void Update() {}

		virtual void SetGameObject(GameObject* gameObject);
		virtual GameObject* GetGameObject() const { return gameObject; }
	protected:
		GameObject* gameObject;
	};
}


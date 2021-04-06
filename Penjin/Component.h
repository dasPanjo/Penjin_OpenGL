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

		GameObject* gameObject;
	};
}


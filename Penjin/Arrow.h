#pragma once
#include "GameObject.h"
#include "StaticMeshComponent.h"

namespace Penjin {
	class Arrow
		: public GameObject
	{
	public:
		Arrow();
		Arrow(std::string name);
		Color color;
		virtual void Update() override;
		void Direction(Vector3 direction);
	private:
		StaticMeshComponent* arrowMesh;
	};
}


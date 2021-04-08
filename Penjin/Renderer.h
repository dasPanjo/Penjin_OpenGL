#pragma once
#include <vector>
#include "StaticMeshComponent.h"
#include "Shader.h"

namespace Penjin {
	class Renderer
	{
	public:
		static void Init();

		static void Bind(StaticMeshComponent* meshFilter);
		static void Unbind(StaticMeshComponent* meshFilter);
		static void Render();

	private:
		static std::vector<StaticMeshComponent*> staticMeshes;

		static void RenderStaticMesh(StaticMeshComponent* meshFilter);
	};
}


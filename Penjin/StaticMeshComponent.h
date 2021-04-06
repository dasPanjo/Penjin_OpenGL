#pragma once
#include "Component.h"
#include "Mesh.h"
#include "Texture.h"

namespace Penjin {
	class StaticMeshComponent
		: public Component
	{
	public:
		StaticMeshComponent();
		virtual void Start() override;
		void BindVao();
		void UnbindVao();

		Mesh* mesh;
		Texture* modelTexture;
	private:
		void InitVao();
		unsigned int vao;
		unsigned int ibo;
		unsigned int vbo;
	};
}


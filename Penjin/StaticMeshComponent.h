#pragma once
#include <string>

#include "Component.h"
#include "Mesh.h"
#include "Texture.h"
#include "Material.h"

namespace Penjin {
	class StaticMeshComponent
		: public Component
	{
	public:
		StaticMeshComponent();
		virtual void Start() override;
		void BindVao();
		void UnbindVao();
		void SetMesh(Mesh* mesh); 
		void LoadMesh(const char* filename);
		void LoadMeshAsync(const char* filename); 
		bool IsInit();
		Mesh GetMesh() const { return *mesh; }

		Material* material;
		bool drawWireframe;
	private:
		Mesh* mesh;
		void LoadMeshNoVao(const char* filename);
		void InitVao();
		unsigned int vao;
		unsigned int ibo;
		unsigned int vbo;

		std::string loadedFile;

		bool initVaoInterrupt;
	};
}


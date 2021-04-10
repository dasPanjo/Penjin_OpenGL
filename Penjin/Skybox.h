#pragma once
#include "Texture.h"
#include "Mesh.h"
#include "Shader.h"

namespace Penjin {
	class Skybox
	{
	public:
		Skybox();
		virtual ~Skybox();

		void LoadTexture(const char* path);
		void LoadTexture(const char* front, const char* back, const char* left, const char* right, const char* top, const char* bottom);

		void Draw();
	protected:
		void InitVao();
		void CreateMesh();
		void CreateShader();

		Mesh* mesh;
		Texture* texture;
		Shader* shader;

		unsigned int vao;
		unsigned int ibo;
		unsigned int vbo;
	};
}


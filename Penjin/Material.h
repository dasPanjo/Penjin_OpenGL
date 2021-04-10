#pragma once
#include "Shader.h"
#include "Texture.h"
#include "Color.h"

namespace Penjin {
	class Material
	{
	public:
		Material();
		virtual void Bind();
		void LoadShader(const char* vertPath, const char* fragPath);
		void LoadTexture(const char* path);

		Color BaseColor;
		
		Shader* shader;
		Texture* texture;
	protected:
	};
}


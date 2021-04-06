#pragma once
#include "Shader.h"
#include "Texture.h"
namespace Penjin {
	class Material
	{
	public:
		virtual void Bind();
		void LoadShader(const char* vertPath, const char* fragPath) { shader = new Shader(vertPath, fragPath); }
	protected:
		Shader* shader;
		Texture* texture;
	};
}


#include "Material.h"
#include "Log.h"

Penjin::Material::Material()
	: shader(new Shader()),
	texture(new Texture()),
	BaseColor(Color())
{
}

void Penjin::Material::Bind()
{
	if (texture != nullptr)
		texture->Bind(0);
	else
		Log::Error("No texture on material!");
	if (shader != nullptr)
		shader->Bind();
	else
		Log::Error("No shader on material!");
}

void Penjin::Material::LoadShader(const char* vertPath, const char* fragPath)
{
	shader->LoadShader(vertPath, fragPath);
}

void Penjin::Material::LoadTexture(const char* filename)
{
	texture->Load(filename);
}

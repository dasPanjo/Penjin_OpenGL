#include "Arrow.h"
#include "File.h"

namespace Penjin {
	Arrow::Arrow() : Arrow("Arrow")
	{
	}
	Arrow::Arrow(std::string name) : GameObject(name)
	{
		arrowMesh = new StaticMeshComponent();
		Mesh* mesh = new Mesh();
		Vertex vertices[] = {
			Vertex({ 0.000000f, 0.000000f, 1.000000f }, { 0.625000f, 0.000000f }, { -0.961300f, 0.000000f, 0.275600f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -0.012830f, -0.012830f, 0.000000f }, { 0.375000f, 0.250000f }, { -1.000000f, 0.000000f, 0.000000f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -0.012830f, 0.012830f, 0.000000f }, { 0.875000f, 0.500000f }, { 0.000000f, 1.000000f, 0.000000f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 0.012830f, -0.012830f, 0.000000f }, { 0.375000f, 0.500000f }, { 0.000000f, -1.000000f, 0.000000f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 0.012830f, 0.012830f, 0.000000f }, { 0.625000f, 0.500000f }, { 1.000000f, 0.000000f, 0.000000f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -0.012830f, -0.012830f, 0.845122f }, { 0.375000f, 0.038720f }, { -0.104400f, 0.000000f, -0.994500f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -0.012830f, 0.012830f, 0.845122f }, { 0.875000f, 0.711280f }, { 0.000000f, 0.104400f, -0.994500f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 0.012830f, -0.012830f, 0.845122f }, { 0.375000f, 0.711280f }, { 0.000000f, -0.104400f, -0.994500f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 0.012830f, 0.012830f, 0.845122f }, { 0.625000f, 0.711280f }, { 0.104400f, 0.000000f, -0.994500f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -0.043485f, -0.043485f, 0.848339f }, { 0.125000f, 0.712085f }, { 0.000000f, -0.104400f, -0.994500f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 0.043485f, 0.043485f, 0.848339f }, { 0.625000f, 0.712085f }, { 0.104400f, 0.000000f, -0.994500f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -0.043485f, 0.043485f, 0.848339f }, { 0.875000f, 0.712085f }, { 0.000000f, 0.104400f, -0.994500f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 0.043485f, -0.043485f, 0.848339f }, { 0.375000f, 0.712085f }, { 0.104400f, 0.000000f, -0.994500f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
		};
		int indices[] = {
			6,1,5,2,3,1,
			12,10,0,9,12,0,
			10,11,0,2,8,4,
			3,5,1,4,7,3,
			11,5,9,0,11,9,
			6,10,8,7,9,5,
			8,12,7,6,2,1,
			2,4,3,2,6,8,
			3,7,5,4,8,7,
			11,6,5,6,11,10,
			7,12,9,8,10,12,
		};
		mesh->vertices = std::vector<Vertex>(vertices, vertices + sizeof vertices / sizeof Vertex);
		mesh->indices = std::vector<unsigned int>(indices, indices + sizeof indices / sizeof (unsigned int));

		arrowMesh->SetMesh(mesh);
		arrowMesh->material->BaseColor = Color(1, 1, 1, 1);
		arrowMesh->material->shader = Shader::GetUnlitShader();
		AddComponent(arrowMesh);

	}
	void Arrow::Update()
	{
		GameObject::Update();
		arrowMesh->material->BaseColor.r = color.r;
		arrowMesh->material->BaseColor.g = color.g;
		arrowMesh->material->BaseColor.b = color.b;
		arrowMesh->material->BaseColor.a = color.a;
	}
	void Arrow::Direction(Vector3 direction) {
		transform.LookAt(transform.position + direction);
	}
}

#include "StaticMeshComponent.h"
#include <GL/glew.h>
#include <thread>

#include "Renderer.h"
#include "ObjectLoader.h"
#include "GameObject.h"

namespace Penjin
{
	StaticMeshComponent::StaticMeshComponent() :
		vao (0),
		ibo (0),
		vbo (0),
		initVaoInterrupt(false),
		drawWireframe(false)
	{
		mesh = new Mesh();
		material = new Material();
	}
	void StaticMeshComponent::Start()
	{
		Renderer::Bind(this);
	}
	void StaticMeshComponent::BindVao()
	{
		if(drawWireframe)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		if (!IsInit()) return;
		glBindVertexArray(vao);
	}
	void StaticMeshComponent::UnbindVao()
	{
		if (drawWireframe)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBindVertexArray(0);
	}
	void StaticMeshComponent::SetMesh(Mesh* mesh)
	{
		this->mesh = mesh;
		InitVao();
	}
	void StaticMeshComponent::LoadMesh(const char* filename)
	{
		SetMesh(ObjectLoader::LoadObjModel(filename));
	}


	void StaticMeshComponent::LoadMeshAsync(const char* filename) {
		std::thread t1(&StaticMeshComponent::LoadMeshNoVao, this, filename);
		t1.detach();
	}

	bool StaticMeshComponent::IsInit()
	{
		if (initVaoInterrupt)
		{
			InitVao();
			initVaoInterrupt = false;
		}
		return vao > 0;
	}

	void StaticMeshComponent::LoadMeshNoVao(const char* filename)
	{
		mesh = ObjectLoader::LoadObjModel(filename);
		Log::Message("Loaded" + std::string(filename));
		initVaoInterrupt = true;
	}

	void StaticMeshComponent::InitVao()
	{
		if (mesh->vertices.size() == 0 || mesh->indices.size() == 0) {
			Log::Error("VAO not initialized. vert_size(" +std::to_string(mesh->indices.size()) + ") indices_size("+ std::to_string(mesh->indices.size()) +")");
			vao = 0;
			return;
		}

		//making vao
		glGenVertexArrays(1, &vao);
		if (vao == 0) {
			Log::Error("VAO could not be initialized!");
			vao = 0;
			return;
		}
		glBindVertexArray(vao);

		//making index buffer
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices.size() * sizeof(unsigned int), &mesh->indices[0], GL_STATIC_DRAW);

		//making vertex buffer
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * sizeof(Vertex), &mesh->vertices[0], GL_STATIC_DRAW);

		//configuring layout for vbo
		//pos
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), (GLvoid*)offsetof(struct Vertex, x));

		//uv
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(Vertex), (GLvoid*)offsetof(struct Vertex, u));

		//normal
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, false, sizeof(Vertex), (GLvoid*)offsetof(struct Vertex, normX));

		//color
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 4, GL_FLOAT, false, sizeof(Vertex), (GLvoid*)offsetof(struct Vertex, r));

	}
}

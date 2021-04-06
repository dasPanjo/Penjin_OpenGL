#include "StaticMeshComponent.h"
#include <GL/glew.h>

#include "Renderer.h"

namespace Penjin 
{
	StaticMeshComponent::StaticMeshComponent()
	{
		mesh = new Mesh();
		unsigned int quadIndices[] =
		{
			0, 1, 2, 0, 2, 3,//back
			4, 5, 6, 4, 6, 7,//right
			8,  9, 10, 8, 10, 11,//top
		   12, 13, 14, 12, 14, 15,//left
		   16, 17, 18, 16, 18, 19,//bottom
		   20, 21, 22, 20, 22, 23//front
		};
		static Vertex quadVertices[] =
		{
			//back face
			Vertex({0.5F, 0.5F, -0.5F}, {1,0}, {0,0,1}, {1,1,1,1}),
			Vertex({-0.5F, 0.5F, -0.5F}, {0,0}, {0,0,1}, {1,1,1,1}),
			Vertex({-0.5F, -0.5F, -0.5F}, {0,1}, {0,0,1}, {1,1,1,1}),
			Vertex({0.5F, -0.5F, -0.5F}, {1,1}, {0,0,1}, {1,1,1,1}),

			//right face
			Vertex({0.5F, 0.5F, 0.5F}, {1,0}, {-1,0,0}, {1,1,1,1}),
			Vertex({0.5F, 0.5F, -0.5F}, {0,0}, {-1,0,0}, {1,1,1,1}),
			Vertex({0.5F, -0.5F, -0.5F}, {0,1}, {-1,0,0}, {1,1,1,1}),
			Vertex({0.5F, -0.5F, 0.5F}, {1,1}, {-1,0,0}, {1,1,1,1}),

			//top face
			Vertex({0.5F, 0.5F, 0.5F}, {1,0}, {0,-1,0}, {1,1,1,1}),
			Vertex({-0.5F, 0.5F, 0.5F}, {0,0}, {0,-1,0}, {1,1,1,1}),
			Vertex({-0.5F, 0.5F, -0.5F}, {0,1}, {0,-1,0}, {1,1,1,1}),
			Vertex({0.5F, 0.5F, -0.5F}, {1,1}, {0,-1,0}, {1,1,1,1}),

			//left face
			Vertex({-0.5F, 0.5F, -0.5F}, {1,0}, {1,0,0}, {1,1,1,1}),
			Vertex({-0.5F, 0.5F, 0.5F}, {0,0}, {1,0,0}, {1,1,1,1}),
			Vertex({-0.5F, -0.5F, 0.5F}, {0,1}, {1,0,0}, {1,1,1,1}),
			Vertex({-0.5F, -0.5F, -0.5F}, {1,1}, {1,0,0}, {1,1,1,1}),

			//bottom face
			Vertex({0.5F, -0.5F, -0.5F}, {1,0}, {0,1,0}, {1,1,1,1}),
			Vertex({-0.5F, -0.5F, -0.5F}, {0,0}, {0,1,0}, {1,1,1,1}),
			Vertex({-0.5F, -0.5F, 0.5F}, {0,1}, {0,1,0}, {1,1,1,1}),
			Vertex({0.5F, -0.5F, 0.5F}, {1,1}, {0,1,0}, {1,1,1,1}),

			//front face
			Vertex({-0.5F, 0.5F, 0.5F}, {1,0}, {0,0,-1}, {1,1,1,1}),
			Vertex({0.5F, 0.5F, 0.5F}, {0,0}, {0,0,-1}, {1,1,1,1}),
			Vertex({0.5F, -0.5F, 0.5F}, {0,1}, {0,0,-1}, {1,1,1,1}),
			Vertex({-0.5F, -0.5F, 0.5F}, {1,1}, {0,0,-1}, {1,1,1,1})
		};

		mesh->vertices = std::vector<Vertex>(quadVertices, quadVertices + sizeof quadVertices / sizeof quadVertices[0]);
		mesh->indices = std::vector<unsigned int>(quadIndices, quadIndices + sizeof quadIndices / sizeof quadIndices[0]);

		modelTexture = new Texture();

		InitVao();
	}
	void StaticMeshComponent::Start()
	{
		Renderer::Bind(this);
	}
	void StaticMeshComponent::BindVao()
	{
		glBindVertexArray(vao);
	}
	void StaticMeshComponent::UnbindVao()
	{
		glBindVertexArray(0);
	}
	void StaticMeshComponent::InitVao()
	{
		//making vao
		glGenVertexArrays(1, &vao);
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
		glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), (GLvoid*)offsetof(struct Vertex, position));

		//uv
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(Vertex), (GLvoid*)offsetof(struct Vertex, uv));

		//normal
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, false, sizeof(Vertex), (GLvoid*)offsetof(struct Vertex, normal));

		//color
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 4, GL_FLOAT, false, sizeof(Vertex), (GLvoid*)offsetof(struct Vertex, color));

	}
}

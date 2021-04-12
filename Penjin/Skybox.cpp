#include "Skybox.h"
#include "Application.h"
#include "Log.h"

namespace Penjin {
	Skybox::Skybox()
		:vao(0),
		ibo(0),
		vbo(0)
	{
		CreateMesh();
		texture = new Texture();
		CreateShader();
		InitVao();
	}
	Skybox::~Skybox()
	{
		delete mesh;
		delete texture;
		delete shader;
	}
	void Skybox::CreateMesh() {
		mesh = new Mesh();
		Vertex vertices[] = {
			Vertex({ -750.0f, -750.0f, 750.0f },	{ 0.25f, 1.0f/3.0f }, { 0.0f, -1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -750.0f, -750.0f, -750.0f },	{ 0.25f, 0.00f }, { 0.0f, -1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 750.0f, -750.0f, 750.0f },		{ 0.50f, 1.0f/3.0f }, { 0.0f, -1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 750.0f, -750.0f, -750.0f },	{ 0.50f, 0.00f }, { 0.0f, -1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -750.0f, -750.0f, -750.0f },	{ 1.00f, 1.0f/3.0f }, { 0.0f, 0.0f, -1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -750.0f, 750.0f, -750.0f },	{ 1.00f, 1.0f/1.5f }, { 0.0f, 0.0f, -1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 750.0f, -750.0f, -750.0f },	{ 0.75f, 1.0f/3.0f }, { 0.0f, 0.0f, -1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 750.0f, 750.0f, -750.0f },		{ 0.75f, 1.0f/1.5f }, { 0.0f, 0.0f, -1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -750.0f, 750.0f, 750.0f },		{ 0.25f, 1.0f/1.5f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -750.0f, 750.0f, -750.0f },	{ 0.25f, 1.00f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 750.0f, 750.0f, 750.0f },		{ 0.50f, 1.0f/1.5f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 750.0f, 750.0f, -750.0f },		{ 0.50f, 1.00f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 750.0f, -750.0f, 750.0f },		{ 0.50f, 1.0f/3.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 750.0f, 750.0f, 750.0f },		{ 0.50f, 1.0f/1.5f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 750.0f, -750.0f, -750.0f },	{ 0.75f, 1.0f/3.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 750.0f, 750.0f, -750.0f },		{ 0.75f, 1.0f/1.5f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -750.0f, -750.0f, 750.0f },	{ 0.25f, 1.0f/3.0f }, { 0.0f, 0.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -750.0f, 750.0f, 750.0f },		{ 0.25f, 1.0f/1.5f }, { 0.0f, 0.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 750.0f, -750.0f, 750.0f },		{ 0.50f, 1.0f/3.0f }, { 0.0f, 0.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ 750.0f, 750.0f, 750.0f },		{ 0.50f, 1.0f/1.5f }, { 0.0f, 0.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -750.0f, -750.0f, 750.0f },	{ 0.25f, 1.0f/3.0f }, { -1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -750.0f, 750.0f, 750.0f },		{ 0.25f, 1.0f/1.5f }, { -1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -750.0f, -750.0f, -750.0f },	{ 0.00f, 1.0f/3.0f }, { -1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
			Vertex({ -750.0f, 750.0f, -750.0f },	{ 0.00f, 1.0f/1.5f }, { -1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }),
		};
		int indices[] = {
			3,0,1,3,2,0,
			5,6,4,5,7,6,
			9,10,11,9,8,10,
			15,12,14,15,13,12,
			19,16,18,19,17,16,
			21,22,20,21,23,22,

		};

		mesh->vertices = std::vector<Vertex>(vertices, vertices + sizeof vertices / sizeof Vertex);
		mesh->indices = std::vector<unsigned int>(indices, indices + sizeof indices / sizeof(unsigned int));
	}
	void Skybox::CreateShader()
	{
		shader = new Shader();
		shader->CreateShader(
			"#version 330 core\n"
			""
			"layout(location = 0) in vec3 a_position;"
			"layout(location = 1) in vec2 a_texUV;"
			"layout(location = 2) in vec4 a_color;"
			""
			"uniform mat4 u_projectionMatrix;"
			"uniform mat4 u_viewMatrix;"
			""
			"out vec2 v_texUV;"
			"out vec4 v_color;"
			""
			"void main() {"
			"	gl_Position = u_projectionMatrix * u_viewMatrix * vec4(a_position, 1);"
			"	v_texUV = a_texUV;"
			"	v_color = a_color;"
			"}",

			"#version 330 core\n"
			""
			"in vec2 v_texUV;"
			"in vec4 v_color;"
			""
			"uniform sampler2D u_texture;"
			""
			"layout(location = 0) out vec4 f_color;"
			""
			"void main() {"
			"	vec4 texColor = texture(u_texture, v_texUV);"
			"	f_color = v_color * texColor;"
			"}");
	}
	void Skybox::LoadTexture(const char* filename)
	{
		texture->Load(filename);
	}
	void Skybox::LoadTexture(const char* front, const char* back, const char* left, const char* right, const char* top, const char* bottom)
	{

	}


	void Skybox::Draw()
	{
		if (vao <= 0) {
			Log::Error("Skybox: vao not initialized!");
			return;
		}
		texture->Bind(0);
		shader->Bind();

		glBindVertexArray(vao);

		Application* application = Application::GetInstance();
		if (application)
		{
			Camera* camera = application->GetCamera();
			if (camera) {
				//Log::Message("Rendering " + gameObject->name + " Indices: " + std::to_string(meshFilter->mesh->indices.size()));
				camera->CalculateViewMatrix(false);
				shader->SetUniformMat4f("u_viewMatrix", camera->GetViewMatrix());
				shader->SetUniformMat4f("u_projectionMatrix", camera->GetProjectionMatrix());
			}
			else {
				Log::Error("No active camera!");
			}
		}

		glDisable(GL_CULL_FACE);
		glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_INT, 0);
		glEnable(GL_CULL_FACE);

		glBindVertexArray(0);
	}

	void Skybox::InitVao()
	{
		if (mesh->vertices.size() == 0 || mesh->indices.size() == 0) {
			Log::Error("VAO not initialized. vert_size(" + std::to_string(mesh->indices.size()) + ") indices_size(" + std::to_string(mesh->indices.size()) + ")");
			vao = 0;
			return;
		}

		//making vao
		if (vao == 0) {
			glGenVertexArrays(1, &vao);
			if (vao == 0) {
				Log::Error("VAO could not be initialized!");
				vao = 0;
				return;
			}
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

		//color
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 4, GL_FLOAT, false, sizeof(Vertex), (GLvoid*)offsetof(struct Vertex, r));

		glBindVertexArray(0);
	}

}

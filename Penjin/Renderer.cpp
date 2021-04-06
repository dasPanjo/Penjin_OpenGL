#include "Renderer.h"
#include "Log.h"
#include "GameObject.h"
#include <GL/glew.h>
#include "glm/vec4.hpp"
#include "glm/ext.hpp"
#include "Application.h"

namespace Penjin {
	std::vector<StaticMeshComponent*> Renderer::staticMeshes;
	Shader* Renderer::shader;

	void Renderer::Init()
	{
		shader = new Shader();
		shader->Bind();
	}

	void Renderer::Bind(StaticMeshComponent* meshFilter)
	{
		if (!meshFilter) {
			Log::Error("Trying to Bind StaticMeshComponent to Renderer, but StaticMeshComponent was nullptr");
			return;
		}
		staticMeshes.push_back(meshFilter);
	}

	void Renderer::Unbind(StaticMeshComponent* meshFilter)
	{
		if (!meshFilter) {
			Log::Error("Trying to Unbind StaticMeshComponent to Renderer, but StaticMeshComponent was nullptr");
			return;
		}
		for (size_t i = staticMeshes.size() - 1; i >= 0; i--)
		{
			if (staticMeshes[i] && staticMeshes[i] == meshFilter)
				staticMeshes.erase(staticMeshes.begin() + i);
		}
	}
	void Renderer::Render()
	{
		for (size_t i = 0; i < staticMeshes.size(); i++)
		{
			if (staticMeshes[i])
				RenderStaticMesh(staticMeshes[i]);
		}
	}
	void Renderer::RenderStaticMesh(StaticMeshComponent* meshFilter)
	{
		GameObject* gameObject = meshFilter->gameObject;
		if (!gameObject) {
			Log::Error("Renderer: no gameObject for staticMeshComponent");
			return;
		}

		meshFilter->BindVao();
		meshFilter->modelTexture->Bind(0);

		glm::mat4 modelMatrix = glm::mat4(1);
		Vector3 position = meshFilter->gameObject->transform.position;
		modelMatrix = glm::translate(modelMatrix, glm::vec3(position.x, position.y, position.z));
		Vector3 rotation = meshFilter->gameObject->transform.rotation;
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		Vector3 scale = meshFilter->gameObject->transform.scale;
		modelMatrix = glm::scale(modelMatrix, glm::vec3(scale.x, scale.y, scale.z));

		shader->Bind();
		shader->SetUniform1i("u_texture", 0);

		shader->SetUniformMat4f("modelMatrix", modelMatrix);
		shader->SetUniformMat3f("normalMatrix", glm::mat3(glm::transpose(glm::inverse(modelMatrix))));

		Application* application = Application::Instance;
		if (application)
		{
			Camera* camera = application->GetCamera();
			if (camera) {
				//Log::Message("Rendering " + gameObject->name + " Indices: " + std::to_string(meshFilter->mesh->indices.size()));
				shader->SetUniformMat4f("viewMatrix", camera->GetViewMatrix());
				shader->SetUniformMat4f("projectionMatrix", camera->GetProjectionMatrix());
			}
			else {
				Log::Error("No active camera!");
			}
		}

		glDisable(GL_CULL_FACE);
		glDrawElements(GL_TRIANGLES, meshFilter->mesh->indices.size(), GL_UNSIGNED_INT, 0);
		glEnable(GL_CULL_FACE);
		meshFilter->UnbindVao();
	}
}

#include "Renderer.h"
#include "Log.h"
#include "GameObject.h"
#include <GL/glew.h>
#include "glm/vec4.hpp"
#include "glm/ext.hpp"
#include "Application.h"

namespace Penjin {
	std::vector<StaticMeshComponent*> Renderer::staticMeshes;

	void Renderer::Init()
	{
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

		if (!meshFilter->IsInit()) return;

		meshFilter->BindVao();
		meshFilter->material->Bind();

		glm::mat4 modelMatrix = glm::mat4(1);

		std::vector<Transform *> transformChain;
		Transform* nextTransform = &meshFilter->gameObject->transform;
		while (nextTransform != nullptr) {
			transformChain.push_back(nextTransform);
			nextTransform = nextTransform->parent;
		}

		for (int i = transformChain.size()-1; i >= 0; i--)
		{
			Vector3 position = transformChain[i]->position;
			Vector3 rotation = transformChain[i]->rotation;
			Vector3 scale = transformChain[i]->scale;

			modelMatrix = glm::translate(modelMatrix, glm::vec3(-position.x, position.y, position.z));

			modelMatrix = glm::rotate(modelMatrix, glm::radians(-rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
			modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
			modelMatrix = glm::rotate(modelMatrix, glm::radians(-rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

			modelMatrix = glm::scale(modelMatrix, glm::vec3(scale.x, scale.y, scale.z));

		}

		Shader* shader = meshFilter->material->GetShader();
		shader->Bind();
		shader->SetUniform1i("u_texture", 0);		

		Color color = meshFilter->material->BaseColor;
		glm::vec4 baseColor(color.r, color.g, color.b, color.a);
		shader->SetUniform4f("u_baseColor", baseColor);

		
		shader->SetUniformMat4f("u_modelMatrix", modelMatrix);
		glm::mat3 normalMatrix(glm::transpose(glm::inverse(modelMatrix)));
		shader->SetUniformMat3f("u_normalMatrix", normalMatrix);

		Application* application = Application::Instance;
		if (application)
		{
			Camera* camera = application->GetCamera();
			if (camera) {
				//Log::Message("Rendering " + gameObject->name + " Indices: " + std::to_string(meshFilter->mesh->indices.size()));
				shader->SetUniformMat4f("u_viewMatrix", camera->GetViewMatrix());
				shader->SetUniformMat4f("u_projectionMatrix", camera->GetProjectionMatrix());
			}
			else {
				Log::Error("No active camera!");
			}
		}

		glDisable(GL_CULL_FACE);
		glDrawElements(GL_TRIANGLES, meshFilter->GetMesh().indices.size(), GL_UNSIGNED_INT, 0);
		glEnable(GL_CULL_FACE);
		meshFilter->UnbindVao();
	}
}

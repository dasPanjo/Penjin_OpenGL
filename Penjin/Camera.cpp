#include "Camera.h"
#include "Application.h"

namespace Penjin {
	Camera::Camera()
		: Camera(60)
	{
		
	}
	Camera::Camera(float fov)
		: Camera(Vector3::Zero, fov)
	{
	}
	Camera::Camera(Vector3 position, float fov)
		: fov(fov)
	{
		transform.position = position;
		name = "Camera";

		CalculateProjectionMatrix();
	}
	void Camera::CalculateProjectionMatrix()
	{
		SDL_Window* window = Application::GetInstance()->GetWindow();
		int width;
		int height;
		SDL_GetWindowSize(window, &width, &height);
		float aspectRatio = (float)width / (float)height;
		projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, 0.1f, 5000.0f);
	}
	void Camera::CalculateViewMatrix(bool translation)
	{
		glm::mat4 viewMatrix = glm::mat4(1);


		Vector3 rotation = transform.rotation;
		viewMatrix = glm::rotate(viewMatrix, glm::radians(-rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		viewMatrix = glm::rotate(viewMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		viewMatrix = glm::rotate(viewMatrix, glm::radians(rotation.y + 180), glm::vec3(0.0f, 1.0f, 0.0f));

		if (translation)
		{
			Vector3 position = transform.position;
			viewMatrix = glm::translate(viewMatrix, glm::vec3(position.x, -position.y, -position.z));
		}

		if (transform.parent != nullptr)
		{
			std::vector<Transform*> transformChain;
			Transform* nextTransform = transform.parent;
			while (nextTransform != nullptr) {
				transformChain.push_back(nextTransform);
				nextTransform = nextTransform->parent;
			}

			for (size_t i = 0; i < transformChain.size(); i++)
			{
				Vector3 position = transformChain[i]->position;
				Vector3 rotation = transformChain[i]->rotation;
				Vector3 scale = transformChain[i]->scale;


				viewMatrix = glm::rotate(viewMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
				viewMatrix = glm::rotate(viewMatrix, glm::radians(-rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
				viewMatrix = glm::rotate(viewMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));

				if(translation) viewMatrix = glm::translate(viewMatrix, glm::vec3(position.x, -position.y, -position.z));

			}
		}
		this->viewMatrix =  viewMatrix;
	}
}

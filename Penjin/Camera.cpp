#include "Camera.h"
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
		: FOV(fov),
		aspectRatio(800.0f/600.0f)
	{
		transform.position = position;
		name = "Camera";

		projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, 0.1f, 1000.0f);
	}
	glm::mat4 Camera::GetViewMatrix()
	{
		glm::mat4 viewMatrix = glm::mat4(1);

		Vector3 rotation = transform.rotation;
		viewMatrix = glm::rotate(viewMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		viewMatrix = glm::rotate(viewMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		viewMatrix = glm::rotate(viewMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

		Vector3 position = transform.position;
		viewMatrix = glm::translate(viewMatrix, glm::vec3(position.x, position.y, position.z));

		return viewMatrix;
	}
}

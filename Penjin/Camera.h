#pragma once
#include "GameObject.h"
#include "glm/vec3.hpp"
#include "glm/ext.hpp"

namespace Penjin {
	class Camera
		: public GameObject
	{
		public:
			/// <summary>Constructor</summary>
			Camera();
			/// <summary>Constructor</summary>
			/// <param name="fov">float: Field of view</param>
			Camera(float fov);
			/// <summary>Constructor</summary>
			/// <param name="position">Vector3: position of the camera</param>
			/// <param name="fov">float: Field of view</param>
			Camera(Vector3 position, float fov);

			float GetFov() const { return fov; }
			void SetFov(float fov) { this->fov = fov; }

			void CalculateProjectionMatrix();
			void CalculateViewMatrix(bool translation = true);

			/// <summary>Returns the view matrix</summary>
			glm::mat4 GetViewMatrix() { return viewMatrix; }

			/// <summary>Returns the projection matrix</summary>
			glm::mat4 GetProjectionMatrix() { return projectionMatrix; }
	protected:
		/// <summary>The projection matrix</summary>
		glm::mat4 projectionMatrix;
		glm::mat4 viewMatrix;

		float fov;
	};
}


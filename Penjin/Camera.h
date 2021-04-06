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

			/// <summary>Field of view</summary>
			float FOV;

			/// <summary>Returns the view matrix</summary>
			glm::mat4 GetViewMatrix();

			/// <summary>Returns the projection matrix</summary>
			glm::mat4 GetProjectionMatrix() { return projectionMatrix; }
	protected:
		/// <summary>The projection matrix</summary>
		glm::mat4 projectionMatrix;

		/// <summary>The current aspectRatio</summary>
		float aspectRatio;

	};
}


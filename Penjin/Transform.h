#pragma once
#include "Vector3.h"

namespace Penjin
{
	class Transform
	{
	public:
		Transform();
		Transform* parent;

		Vector3 position;
		Vector3 rotation;
		Vector3 scale;

		void Translate(float x, float y, float z);
		void Translate(Vector3 vector) { Translate(vector.x, vector.y, vector.z); }

		void Rotate(float x, float y, float z);
		void Rotate(Vector3 vector) { Rotate(vector.x, vector.y, vector.z); }

		void LookAt(float x, float y, float z);
		void LookAt(Vector3 vector) { LookAt(vector.x, vector.y, vector.z); }

		Vector3 GetForwardVector();
		Vector3 GetRightVector();
		Vector3 GetUpVector();

		Vector3 GetWorldPosition();
	};
}


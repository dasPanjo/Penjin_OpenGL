#pragma once
#include "Vector3.h"
#include "Quaternion.h"

namespace Penjin
{
	class Transform
	{
	public:
		Transform();

		Vector3 position;
		Vector3 rotation;
		Vector3 scale;

		void Translate(float x, float y, float z);
		void Translate(Vector3 vector) { Translate(vector.x, vector.y, vector.z); }

		void Rotate(float x, float y, float z);
		void Rotate(Vector3 vector) { Rotate(vector.x, vector.y, vector.z); }

		void LookAt(float x, float y, float z);
		void LookAt(Vector3 vector) { LookAt(vector.x, vector.y, vector.z); }
	};
}


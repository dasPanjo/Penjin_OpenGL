#pragma once
#include "Vector3.h"

namespace Penjin {
	class Quaternion
	{
	public:
		float x, y, z, w;

		void Rotate(float x, float y, float z);
		void Rotate(Vector3 vector) { Rotate(vector.x, vector.y, vector.z); }

		void Normalize();

		Vector3 GetEuler();

		static Quaternion Euler(float x, float y, float z);

	};
}


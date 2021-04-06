#include "Quaternion.h"

# define M_PI 3.14159265358979323846  /* pi */

namespace Penjin
{
	void Quaternion::Rotate(float x, float y, float z)
	{
		this->x += x;
		this->y += y;
		this->z += z;
	}

	void Quaternion::Normalize()
	{
		float length = sqrt(x * x + y * y + z * z + w * w);
		if (length == 0) return;
		x /= length;
		y /= length;
		z /= length;
		w /= length;
	}

	Vector3 Quaternion::GetEuler()
	{
		return Vector3(x,y,z);
	}

	Quaternion Quaternion::Euler(float x, float y, float z)
	{
		Quaternion q;
		q.x = x;
		q.y = y;
		q.z = z;
		return q;
	}

}
#include "Transform.h"
#include "Log.h"
#include "glm/vec3.hpp"
#include "glm/ext.hpp"

namespace Penjin {
	Transform::Transform()
		: position(0.0f, 0.0f, 0.0f),
		rotation(0.0f,0.0f,0.0f),
		scale(1.0f,1.0f,1.0f)
	{
	}
	void Transform::Translate(float x, float y, float z)
	{
		position.x += x;
		position.y += y;
		position.z += z;
	}

	void Transform::Rotate(float x, float y, float z)
	{
		rotation.x += x;
		rotation.y += y;
		rotation.z += z;
	}
	void Transform::LookAt(float x, float y, float z)
	{

	}
}

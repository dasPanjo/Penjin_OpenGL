#include "Transform.h"
#include "Log.h"
#include "glm/vec3.hpp"
#include "glm/ext.hpp"

namespace Penjin {

#define DEG_2_RAD 0.01745329251f

	Transform::Transform()
		: position(0.0f, 0.0f, 0.0f),
		rotation(0.0f, 0.0f, 0.0f),
		scale(1.0f, 1.0f, 1.0f),
		parent(nullptr)
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
		Vector3 dir(x - this->position.x, y - this->position.y, z - this->position.z);

		float pitch = atan2(dir.y, sqrt(dir.x * dir.x + dir.z * dir.z)) * (180 / 3.14f);
		float yaw = atan2(dir.x, dir.z) * (180 / 3.14f);

		rotation.x = -pitch;
		rotation.y = yaw;
		rotation.z = 0;
	}
	Vector3 Transform::GetForwardVector() {
		float xPos = cos(rotation.x * DEG_2_RAD) * sin(rotation.y * DEG_2_RAD);
		float yPos = sin(rotation.x * DEG_2_RAD) * (-1);
		float zPos = cos(rotation.x * DEG_2_RAD) * cos(rotation.y * DEG_2_RAD);
		Vector3 vec(xPos, yPos, zPos);
		vec.Normalize();
		return vec;
	}
	Vector3 Transform::GetRightVector() {
		float xPos = 
										  cos(rotation.y * DEG_2_RAD) * cos(rotation.z * DEG_2_RAD) + 
			sin(rotation.x * DEG_2_RAD) * sin(rotation.y * DEG_2_RAD) * sin(rotation.z * DEG_2_RAD);
		float yPos = 
			cos(rotation.x * DEG_2_RAD) *								sin(rotation.z * DEG_2_RAD);
		float zPos = 
										  sin(rotation.y * DEG_2_RAD) * cos(rotation.z * DEG_2_RAD) * (-1) + 
			sin(rotation.x * DEG_2_RAD) * cos(rotation.y * DEG_2_RAD) * sin(rotation.z * DEG_2_RAD);
		Vector3 vec(xPos, yPos, zPos);
		vec.Normalize();
		return vec;
	}
	Vector3 Transform::GetUpVector() {
		float xPos = sin(rotation.x * DEG_2_RAD) * sin(rotation.y * DEG_2_RAD) * cos(rotation.z * DEG_2_RAD) + sin(rotation.z * DEG_2_RAD) * cos(rotation.y * DEG_2_RAD) * (-1);
		float yPos = cos(rotation.x * DEG_2_RAD) * cos(rotation.z * DEG_2_RAD);
		float zPos = cos(rotation.y * DEG_2_RAD) * sin(rotation.x * DEG_2_RAD) * cos(rotation.z * DEG_2_RAD) + sin(rotation.z * DEG_2_RAD) * sin(rotation.y * DEG_2_RAD);
		Vector3 vec(xPos, yPos, zPos);
		vec.Normalize();
		return vec;
	}
}

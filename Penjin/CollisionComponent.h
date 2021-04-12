#pragma once 
#include <stdio.h>
#include <btBulletDynamicsCommon.h>
#include "Component.h"
#include "Vector3.h"

namespace Penjin
{
	class CollisionComponent
		: public Component
	{
	public:
		CollisionComponent(Vector3 position, float mass);

		virtual void SetGameObject(GameObject* gameObject) override;

		void SetPosition(Vector3 position);
		void SetRotation(Vector3 rotation);
		Vector3 ToVector3(btQuaternion quaternion);

		virtual void Update() override;

	private:
		btRigidBody* body;
		btCollisionShape* collisionShape;
		btDefaultMotionState* myMotionState;
		btTransform transform;

		float mass;
	};
}


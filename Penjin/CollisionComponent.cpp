#include "CollisionComponent.h"
#include "GameObject.h"
#include "Application.h"

namespace Penjin {
	CollisionComponent::CollisionComponent(Vector3 position, float mass)
		:mass(mass)
	{
		collisionShape = new btBoxShape(btVector3(btScalar(1.), btScalar(1.), btScalar(1.)));

		transform = btTransform();
		transform.setIdentity();
		transform.setOrigin(btVector3(position.x, position.y, position.z));
		//transform.setRotation(btQuaternion(btVector3(1, 1, 1), SIMD_PI / 10.));
		
		btScalar sMass(mass);

		//rigidbody is dynamic if and only if mass is non zero, otherwise static
		bool isDynamic = (sMass != 0.f);

		btVector3 localInertia(0, 0, 0);
		if (isDynamic)
			collisionShape->calculateLocalInertia(sMass, localInertia);

		//using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
		myMotionState = new btDefaultMotionState(transform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(sMass, myMotionState, collisionShape, localInertia);
		body = new btRigidBody(rbInfo);
		body->setFriction(1);
		//body->setAngularVelocity(btVector3(0, 1, 0));

		//add the body to the dynamics world
		Application::GetInstance()->GetDynamicWorld()->AddRigidBody(body);
	}
	void CollisionComponent::SetGameObject(GameObject* gameObject)
	{
		Component::SetGameObject(gameObject);
	}
	void CollisionComponent::SetPosition(Vector3 position)
	{
		//transform.setOrigin(btVector3(position.x, position.y, position.z));
	}
	void CollisionComponent::Update()
	{
		btTransform trans;
		if (body && body->getMotionState())
		{
			body->getMotionState()->getWorldTransform(trans);
		}
		float mat[16];
		trans.getOpenGLMatrix(mat);

		btVector3 origin = trans.getOrigin();
		gameObject->transform.position.x = (float)origin.getX();
		gameObject->transform.position.y = (float)origin.getY();
		gameObject->transform.position.z = (float)origin.getZ();

		for (size_t i = 0; i < 16; i++)
		{
			std::cout << mat[i] << " ";
		}
		std::cout << std::endl;
	}
	void CollisionComponent::SetRotation(Vector3 rotation)
	{
		//transform.getRotation().setEuler(rotation.x, rotation.y, rotation.z);
	}

}
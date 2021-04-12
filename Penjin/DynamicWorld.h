#pragma once
#include <btBulletDynamicsCommon.h>

namespace Penjin
{
	class DynamicWorld
	{
	public:
		DynamicWorld();
		virtual ~DynamicWorld();

		void Update();

		void AddRigidBody(btRigidBody* shape);
	private:
		btDefaultCollisionConfiguration* collisionConfiguration;
		btCollisionDispatcher* dispatcher;
		btBroadphaseInterface* overlappingPairCache;
		btSequentialImpulseConstraintSolver* solver;
		btDiscreteDynamicsWorld* dynamicsWorld;

	};
}


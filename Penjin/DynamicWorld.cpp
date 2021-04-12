#include "DynamicWorld.h"
#include <btBulletDynamicsCommon.h>
#include "Times.h"

namespace Penjin {
	DynamicWorld::DynamicWorld() 
		: collisionConfiguration(nullptr),
		dispatcher(nullptr),
		overlappingPairCache(nullptr),
		solver(nullptr),
		dynamicsWorld(nullptr)

	{

		///-----includes_end-----

		int i;
		///-----initialization_start-----

		///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
		collisionConfiguration = new btDefaultCollisionConfiguration();

		///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
		dispatcher = new btCollisionDispatcher(collisionConfiguration);

		///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
		overlappingPairCache = new btDbvtBroadphase();

		///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
		solver = new btSequentialImpulseConstraintSolver;

		dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);

		dynamicsWorld->setGravity(btVector3(0, -10, 0));
	}

	DynamicWorld::~DynamicWorld()
	{
		////remove the rigidbodies from the dynamics world and delete them
		//for (size_t i = dynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--)
		//{
		//	btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
		//	btRigidBody* body = btRigidBody::upcast(obj);
		//	if (body && body->getMotionState())
		//	{
		//		delete body->getMotionState();
		//	}
		//	dynamicsWorld->removeCollisionObject(obj);
		//	delete obj;
		//}

		////delete collision shapes
		//for (int j = 0; j < collisionShapes.size(); j++)
		//{
		//	btCollisionShape* shape = collisionShapes[j];
		//	collisionShapes[j] = 0;
		//	delete shape;
		//}

		////delete dynamics world
		//delete dynamicsWorld;

		////delete solver
		//delete solver;

		////delete broadphase
		//delete overlappingPairCache;

		////delete dispatcher
		//delete dispatcher;

		//delete collisionConfiguration;

		////next line is optional: it will be cleared by the destructor when the array goes out of scope
		//collisionShapes.clear();
	}

	void DynamicWorld::Update()
	{
		dynamicsWorld->stepSimulation(Time::GetDeltaTime(), 10);
		for (int j = dynamicsWorld->getNumCollisionObjects() - 1; j >= 0; j--)
		{
			btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[j];
			btRigidBody* body = btRigidBody::upcast(obj);
			btTransform trans;
			if (body && body->getMotionState())
			{
				body->getMotionState()->getWorldTransform(trans);
			}
			else
			{
				trans = obj->getWorldTransform();
			}
		}
	}

	void DynamicWorld::AddRigidBody(btRigidBody* rigidBody)
	{
		dynamicsWorld->addRigidBody(rigidBody);
	}


}
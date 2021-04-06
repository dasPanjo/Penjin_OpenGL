#include "RotateAroundPointComponent.h"
#include <GameObject.h>
#include <Times.h>
#include <Log.h>

RotateAroundPointComponent::RotateAroundPointComponent(Penjin::Vector3 center, float radius, float speed, bool lookAtCenter)
	:center(center),
	radius(radius),
	speed(speed),
	progress(0),
	lookAtCenter(lookAtCenter)
{
}

void RotateAroundPointComponent::Update()
{
	float deg2rad = (3.141592653f / 180.0f);
	progress += Penjin::Time::GetDeltaTime() * speed;
	gameObject->transform.position = Penjin::Vector3(sin(progress * deg2rad) * radius, 0, cos(progress * deg2rad) * radius) + center;
	if (lookAtCenter)
	{
		gameObject->transform.LookAt(center);
		//gameObject->transform.rotation.y = progress;
		Penjin::Log::Message(gameObject->transform.position.ToString() + " - " + gameObject->transform.rotation.ToString());
	}
	//gameObject->transform.rotation = Penjin::Vector3(0.0f, 0, 0);
	//gameObject->transform.position = Penjin::Vector3(-1, 2.0f, -3.0f); 
	//gameObject->transform.LookAt(0, 0, 0);
}

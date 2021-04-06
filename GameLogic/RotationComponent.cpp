#include "RotationComponent.h"
#include <GameObject.h>
#include <Times.h>

RotationComponent::RotationComponent()
	:RotationComponent(0,0,0)
{
}

RotationComponent::RotationComponent(float x, float y, float z)
	: RotationComponent(Penjin::Vector3(x,y,z))
{
}

RotationComponent::RotationComponent(Penjin::Vector3 speed)
	: speed(speed)
{
}

void RotationComponent::Update()
{
	float deltaTime = Penjin::Time::GetDeltaTime();
	if (deltaTime <= 0) deltaTime = 0.001f;
	gameObject->transform.Rotate(speed.x, speed.y * deltaTime, speed.z);
}

#include "RotateAroundPointComponent.h"
#include <GameObject.h>
#include <Times.h>
#include <Log.h>
#include <cmath>

RotateAroundPointComponent::RotateAroundPointComponent(Penjin::Vector3 center, float radius, float speed)
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
	gameObject->transform.position = Penjin::Vector3(sin(progress * deg2rad) * radius, 10, cos(progress * deg2rad) * radius) + center;
	gameObject->transform.LookAt(center);

}

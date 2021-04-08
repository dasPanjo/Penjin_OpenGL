#include "RotationComponent.h"
#include <GameObject.h>
#include <Times.h>

RotationComponent::RotationComponent()
	:RotationComponent(0, 0, 0)
{
}

RotationComponent::RotationComponent(float x, float y, float z)
	: RotationComponent(Penjin::Vector3(x, y, z))
{
}

RotationComponent::RotationComponent(Penjin::Vector3 speed)
	: speed(speed),
	phase(0),
	progress(0)
{
}

void RotationComponent::Update()
{
	switch (phase) {
	case 0:
		gameObject->transform.Rotate(Penjin::Time::GetDeltaTime() * 45.0f, 0, 0);
		break;
	case 1:
		gameObject->transform.Rotate(0, Penjin::Time::GetDeltaTime() * 45.0f, 0);
		break;
	case 2:
		gameObject->transform.Rotate(0, 0, Penjin::Time::GetDeltaTime() * 45.0f);
		break;
	}

	progress += Penjin::Time::GetDeltaTime();
	if (progress >= 1.0f) {
		progress = 0;
		phase++;
		if (phase > 2)
			phase = 0;
	}

}

#include "LookAtComponent.h"
#include <GameObject.h>

void LookAtComponent::Update()
{
	switch (direction) {
	case Direction::ForwardVector:
		gameObject->transform.position = this->lookAt->position + this->lookAt->GetForwardVector() * 0.02f;
		gameObject->transform.LookAt(this->lookAt->position + this->lookAt->GetForwardVector());
		break;
	case Direction::UpVector:
		gameObject->transform.position = this->lookAt->position + this->lookAt->GetUpVector() * 0.02f;
		gameObject->transform.LookAt(this->lookAt->position + this->lookAt->GetUpVector());
		break;
	case Direction::RightVector:
		gameObject->transform.position = this->lookAt->position + this->lookAt->GetRightVector() * 0.02f;
		gameObject->transform.LookAt(this->lookAt->position + this->lookAt->GetRightVector());
		break;
	}
}

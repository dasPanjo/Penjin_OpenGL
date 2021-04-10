#pragma once
#include <Component.h>
#include <Transform.h>

class LookAtComponent
	
	:public Penjin::Component
{
public:

	enum class Direction {
		Position,
		UpVector,
		RightVector,
		ForwardVector
	};

	virtual void Update() override;
	Penjin::Vector3 position;
	Penjin::Transform* lookAt;
	Direction direction;
};

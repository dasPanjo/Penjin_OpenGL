#pragma once
#include <Component.h>
#include <Transform.h>

class LookAtComponent
	
	:public Penjin::Component
{
public:

	enum class Direction {
		UpVector,
		RightVector,
		ForwardVector
	};

	virtual void Update() override;
	Penjin::Transform* lookAt;
	Direction direction;
};


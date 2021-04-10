#pragma once
#include <Component.h>
class CameraMovement
	: public Penjin::Component
{
public:
	virtual void Update() override;
	float speed = 2.0f;
};


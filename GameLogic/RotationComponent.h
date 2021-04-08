#pragma once
#include <Component.h>
#include <Vector3.h>

class RotationComponent
	:public Penjin::Component
{
public:
	RotationComponent();
	RotationComponent(float x, float y, float z);
	RotationComponent(Penjin::Vector3 speed);

	virtual void Update() override;
	Penjin::Vector3 speed;
	int phase;
	float progress;
};


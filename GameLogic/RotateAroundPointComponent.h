#pragma once
#include <Component.h>
#include <Vector3.h>

class RotateAroundPointComponent
	: public Penjin::Component
{
public:
	RotateAroundPointComponent(Penjin::Vector3 center, float radius, float speed = 10, bool lookAtCenter = false);

	virtual void Update() override;

	Penjin::Vector3 center;
	float radius;
	float speed;
	bool lookAtCenter;
private:
	float progress;
};


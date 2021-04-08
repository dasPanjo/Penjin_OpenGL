#include "CameraMovement.h"
#include <GameObject.h>
#include <Input.h>
#include <Times.h>

void CameraMovement::Update()
{
	if (Penjin::Input::IsKeyDown(SDLK_d)) {
		gameObject->transform.position += gameObject->transform.GetRightVector() * Penjin::Time::GetDeltaTime() * 2.0f;
	}
	if (Penjin::Input::IsKeyDown(SDLK_a)) {
		gameObject->transform.position -= gameObject->transform.GetRightVector() * Penjin::Time::GetDeltaTime() * 2.0f;
	}
	if (Penjin::Input::IsKeyDown(SDLK_w)) {
		gameObject->transform.position += gameObject->transform.GetForwardVector() * Penjin::Time::GetDeltaTime() * 2.0f;
	}
	if (Penjin::Input::IsKeyDown(SDLK_s)) {
		gameObject->transform.position -= gameObject->transform.GetForwardVector() * Penjin::Time::GetDeltaTime() * 2.0f;
	}
	if (Penjin::Input::IsKeyDown(SDLK_e)) {
		gameObject->transform.position += gameObject->transform.GetUpVector() * Penjin::Time::GetDeltaTime() * 2.0f;
	}
	if (Penjin::Input::IsKeyDown(SDLK_q)) {
		gameObject->transform.position -= gameObject->transform.GetUpVector() * Penjin::Time::GetDeltaTime() * 2.0f;
	}

	gameObject->transform.Rotate(Penjin::Vector3(Penjin::Input::mouseSpeed.y, Penjin::Input::mouseSpeed.x, 0));
	if (gameObject->transform.rotation.x < -90)
		gameObject->transform.rotation.x = -90;
	if (gameObject->transform.rotation.x > 90)
		gameObject->transform.rotation.x = 90;

}

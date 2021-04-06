#include "Application3D.h"
#include <iostream>
#include <string>
#include <Times.h>
#include <Log.h>
#include <StaticMeshComponent.h>
#include "RotationComponent.h"
#include "RotateAroundPointComponent.h"


bool Application3D::Startup()
{
	if (!Application::Startup()) return false;

	Penjin::Log::Message("Starting...");

	camera = new Penjin::Camera(Penjin::Vector3(0, 0, -3), 60);
	//camera->transform.rotation = Penjin::Quaternion::Euler(0, 0, 0);

	cube = new Penjin::GameObject("TestObject");
	//cube->transform.position.x = 0;
	//cube->transform.position.z = 0;
	//cube->transform.LookAt(0, 0, 0);

	Penjin::StaticMeshComponent* cube_staticMeshComponent = new Penjin::StaticMeshComponent();
	cube_staticMeshComponent->modelTexture->Load("Images/Brick.png");
	cube->AddComponent(cube_staticMeshComponent);

	RotationComponent* cube_rotationComponent = new RotationComponent();
	cube_rotationComponent->speed = Penjin::Vector3(0, 20, 0);
	cube->AddComponent(cube_rotationComponent);

	RotateAroundPointComponent* camera_rotateAroundPointComponent = new RotateAroundPointComponent(Penjin::Vector3::Zero, 2, 50.0f, true);
	//cube->AddComponent(camera_rotateAroundPointComponent);

	Penjin::Log::Message("Camera: " + camera->transform.position.ToString() + " - " + camera->transform.rotation.ToString());
	Penjin::Log::Message("Cube: " + cube->transform.position.ToString() + " - " + cube->transform.rotation.ToString());

	return true;
}

void Application3D::Shutdown()
{
	Application::Shutdown();
	Penjin::Log::Message("Shutting down...");
}

void Application3D::Update()
{

	Application::Update();
	SDL_SetWindowTitle(GetWindow(), ("FPS " + std::to_string(Penjin::Time::GetFps()) + " ( " + std::to_string(Penjin::Time::GetDeltaTime()) + "ms )").c_str());

	camera->Update();
	cube->Update();
}

void Application3D::Draw()
{
	Application::Draw();
}

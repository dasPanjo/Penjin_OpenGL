#include "Application3D.h"
#include <iostream>
#include <string>
#include <Times.h>
#include <Log.h>
#include <StaticMeshComponent.h>
#include <Color.h>
#include <AssetLoader.h>
#include "RotationComponent.h"
#include "RotateAroundPointComponent.h"
#include "LookAtComponent.h"
#include "CameraMovement.h"
#include <Skybox.h>
#include <Renderer.h>
#include <chrono>


bool Application3D::Startup()
{
	if (!Application::Startup()) return false;

	Penjin::Log::Message("Starting...");

	CameraMovement* cameraMovement = new CameraMovement();
	cameraMovement->speed = 20;
	camera->AddComponent(cameraMovement);

	LookAtComponent* lookAt = new LookAtComponent();
	lookAt->direction = LookAtComponent::Direction::Position;
	lookAt->position = Penjin::Vector3(0, 0, 0);
	//camera->AddComponent(lookAt);

	Penjin::Mesh* meshArrow = Penjin::AssetLoader::LoadModel("Models/Arrow");
	Penjin::Mesh* meshPlate = Penjin::AssetLoader::LoadModel("Models/Plate");

	//Arrow
	arrow = new Penjin::GameObject("Arrow");
	arrow->transform.position = Penjin::Vector3(0, 2.5f, 0);
	arrow->transform.rotation = Penjin::Vector3(90, 90, 90);
	arrow->transform.scale = Penjin::Vector3(0.5f, 0.5f, 0.5f);

	Penjin::StaticMeshComponent* arrow_staticMeshComponent = new Penjin::StaticMeshComponent();
	arrow_staticMeshComponent->LoadMeshAsync("Models/Cube");
	arrow_staticMeshComponent->material->LoadTexture("Images/WhitePixel.png");
	arrow_staticMeshComponent->material->shader = Penjin::Shader::GetUnlitShader();
	arrow_staticMeshComponent->drawWireframe = false;
	arrow_staticMeshComponent->material->BaseColor = Penjin::Color(1, 1, 1);
	arrow->AddComponent(arrow_staticMeshComponent);

	RotationComponent* cube_rotationComponent = new RotationComponent();
	arrow->AddComponent(cube_rotationComponent);

	//CubeX
	cubeX = new Penjin::GameObject("CubeX"); 
	cubeX->transform.position = Penjin::Vector3(0, 0, 0);
	cubeX->transform.rotation = Penjin::Vector3(0, 90, 0);
	cubeX->transform.parent = &arrow->transform;

	Penjin::StaticMeshComponent* cube_x_staticMeshComponent = new Penjin::StaticMeshComponent();
	cube_x_staticMeshComponent->SetMesh(meshPlate);
	cube_x_staticMeshComponent->material->LoadTexture("Images/WhitePixel.png");
	cube_x_staticMeshComponent->material->shader = Penjin::Shader::GetUnlitShader();
	cube_x_staticMeshComponent->drawWireframe = false;
	cube_x_staticMeshComponent->material->BaseColor = Penjin::Color(1, 0, 0);
	cubeX->AddComponent(cube_x_staticMeshComponent);

	//CubeY
	cubeY = new Penjin::GameObject("CubeY");
	cubeY->transform.position = Penjin::Vector3(0, 0, 0);
	cubeY->transform.rotation = Penjin::Vector3(-90, 0, 0);
	cubeY->transform.parent = &arrow->transform;

	Penjin::StaticMeshComponent* cube_y_staticMeshComponent = new Penjin::StaticMeshComponent();
	cube_y_staticMeshComponent->SetMesh(meshPlate);
	cube_y_staticMeshComponent->material->LoadTexture("Images/WhitePixel.png");
	cube_y_staticMeshComponent->material->shader = Penjin::Shader::GetUnlitShader();
	cube_y_staticMeshComponent->drawWireframe = false;
	cube_y_staticMeshComponent->material->BaseColor = Penjin::Color(0, 1, 0);
	cubeY->AddComponent(cube_y_staticMeshComponent);

	//CubeZ
	cubeZ = new Penjin::GameObject("CubeZ");
	cubeZ->transform.position = Penjin::Vector3(0, 0, 0);
	cubeZ->transform.rotation = Penjin::Vector3(0, 0, -90);
	cubeZ->transform.parent = &arrow->transform;

	Penjin::StaticMeshComponent* cube_z_staticMeshComponent = new Penjin::StaticMeshComponent();
	cube_z_staticMeshComponent->SetMesh(meshPlate);
	cube_z_staticMeshComponent->material->LoadTexture("Images/WhitePixel.png");
	cube_z_staticMeshComponent->material->shader = Penjin::Shader::GetUnlitShader();
	cube_z_staticMeshComponent->drawWireframe = false;
	cube_z_staticMeshComponent->material->BaseColor = Penjin::Color(0, 0, 1);
	cubeZ->AddComponent(cube_z_staticMeshComponent);


	//ArrowX

	arrowX = new Penjin::Arrow("ArrowX");
	arrowX->transform.position = Penjin::Vector3(0.2f, 0, 0);
	arrowX->transform.rotation = Penjin::Vector3(0, 0, -90);	
	arrowX->transform.scale = Penjin::Vector3(0.5f, 0.5f, 0.5f);

	arrowX->color = Penjin::Color(1.0f, 0.0f, 0.0f);

	LookAtComponent* arrow_x_lookAtComponent = new LookAtComponent();
	arrow_x_lookAtComponent->lookAt = &arrow->transform;
	arrow_x_lookAtComponent->direction = LookAtComponent::Direction::RightVector;
	arrowX->AddComponent(arrow_x_lookAtComponent);

	//ArrowY
	arrowY = new Penjin::Arrow("ArrowY");
	arrowY->transform.position = Penjin::Vector3(0, 0.2f, 0);
	arrowY->transform.rotation = Penjin::Vector3(0, 0, 0);
	arrowY->transform.scale = Penjin::Vector3(0.5f, 0.5f, 0.5f);
	arrowY->color = Penjin::Color(0.0f, 1.0f, 0.0f);

	LookAtComponent* arrow_y_lookAtComponent = new LookAtComponent();
	arrow_y_lookAtComponent->lookAt = &arrow->transform;
	arrow_y_lookAtComponent->direction = LookAtComponent::Direction::UpVector;
	arrowY->AddComponent(arrow_y_lookAtComponent);


	//ArrowZ
	arrowZ = new Penjin::Arrow("ArrowZ");
	arrowZ->transform.position = Penjin::Vector3(0, 0, 0.2f);
	arrowZ->transform.rotation = Penjin::Vector3(90, 0, 0);
	arrowZ->transform.scale = Penjin::Vector3(0.5f, 0.5f, 0.5f);
	arrowZ->color = Penjin::Color(0.0f, 0.0f, 1.0f);

	LookAtComponent* arrow_z_lookAtComponent = new LookAtComponent();
	arrow_z_lookAtComponent->lookAt = &arrow->transform;
	arrow_z_lookAtComponent->direction = LookAtComponent::Direction::ForwardVector;
	arrowZ->AddComponent(arrow_z_lookAtComponent);
	

	weirdCube = new Penjin::GameObject("TestObject");
	weirdCube->transform.position = Penjin::Vector3(0, 1, 0);
	//weirdCube->transform.scale = Penjin::Vector3(0.5f, 0.5f, 0.5f);

	//Cube
	Penjin::StaticMeshComponent* weirdCube_staticMeshComponent = new Penjin::StaticMeshComponent();
	weirdCube_staticMeshComponent->LoadMeshAsync("Models/WeirdCube");
	//weirdCube_staticMeshComponent->material->BaseColor = Penjin::Color(0.7f, 0.7f, 0.7f, 1.0f);
	weirdCube_staticMeshComponent->drawWireframe = false;
	weirdCube->AddComponent(weirdCube_staticMeshComponent);

	monkey = new Penjin::GameObject("Monkey");
	monkey->transform.position = Penjin::Vector3(0.0f, 0.0f, 0.0f);
	monkey->transform.rotation = Penjin::Vector3(0.0f, 0.0f, 0.0f);

	//Cube
	Penjin::StaticMeshComponent* monkey_staticMeshComponent = new Penjin::StaticMeshComponent();

	auto start = std::chrono::high_resolution_clock::now();
	monkey_staticMeshComponent->LoadMesh("Models/CityBlock");
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	Penjin::Log::Message("Loaded in " + std::to_string(elapsed.count()) + " seconds!");
	monkey_staticMeshComponent->material->BaseColor = Penjin::Color(0.7f, 0.7f, 0.7f, 1.0f);
	monkey_staticMeshComponent->drawWireframe = false;
	monkey->AddComponent(monkey_staticMeshComponent);
		
	return true;
}

void Application3D::DrawInitFrame()
{
	camera = new Penjin::Camera(Penjin::Vector3(0, 1, -3), 60);
	camera->transform.rotation = Penjin::Vector3(0, 0, 0);

	skybox = new Penjin::Skybox();
	skybox->LoadTexture("Images/Daylight Box UV.png");
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
	weirdCube->Update();
	monkey->Update();
	
	arrow->Update();
	cubeX->Update();
	cubeY->Update();
	cubeZ->Update();
	arrowX->Update();
	arrowY->Update();
	arrowZ->Update();
	
}

void Application3D::Draw()
{
	Application::Draw();
}

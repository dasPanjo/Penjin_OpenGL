#include "Application3D.h"
#include <iostream>
#include <string>
#include <Times.h>
#include <Log.h>
#include <StaticMeshComponent.h>
#include <Color.h>d
#include <AssetLoader.h>
#include "RotationComponent.h"
#include "RotateAroundPointComponent.h"
#include "LookAtComponent.h"
#include "CameraMovement.h"
#include <Skybox.h>
#include <Renderer.h>
#include <chrono>
#include <CollisionComponent.h>

Application3D::~Application3D()
{
	Application::~Application();

}

bool Application3D::Awake()
{
	if (!Application::Awake()) return false;
	return true;
}
void Application3D::Startup()
{
	Penjin::Log::Message("Starting...");
	
	//Penjin::Mesh* mesh = Penjin::AssetLoader::LoadModel("Models/GTA");

	if (camera == nullptr) camera = new Penjin::Camera();
	camera->transform.position = Penjin::Vector3(0, 1, -10);
	camera->transform.rotation = Penjin::Vector3(0, 0, 0);

	if (skybox == nullptr) skybox = new Penjin::Skybox();
	skybox->LoadTexture("Images/Daylight Box UV.png");

	if (dynamicWorld == nullptr) dynamicWorld = new Penjin::DynamicWorld();


	CameraMovement* cameraMovement = new CameraMovement();
	cameraMovement->speed = 10;
	camera->AddComponent(cameraMovement);

	RotateAroundPointComponent* cameraRotation = new RotateAroundPointComponent(Penjin::Vector3(0, 2, 0), 15, 40);
	//camera->AddComponent(cameraRotation);

	cube1 = new Penjin::GameObject("Cube1");
	//cube1->transform.scale = Penjin::Vector3(0.5f, 0.5f, 0.5f);

	Penjin::StaticMeshComponent* cube1_staticMesh = new Penjin::StaticMeshComponent();
	cube1_staticMesh->LoadMesh("Models/Cube");
	cube1->AddComponent(cube1_staticMesh);
	cube1_staticMesh->material->BaseColor = Penjin::Color(0, 0, 1, 1);

	Penjin::CollisionComponent* cube1_collision = new Penjin::CollisionComponent(Penjin::Vector3(0, 10, 0), 1);
	cube1->AddComponent(cube1_collision);





	cube2 = new Penjin::GameObject("Cube2");
	//cube2->transform.scale = Penjin::Vector3(0.5f, 0.5f, 0.5f);
	Penjin::StaticMeshComponent* cube2_staticMesh = new Penjin::StaticMeshComponent();
	cube2_staticMesh->LoadMesh("Models/Cube");
	cube2->AddComponent(cube2_staticMesh);

	Penjin::CollisionComponent* cube2_collision = new Penjin::CollisionComponent(Penjin::Vector3(1.1, 0, 1), 0);
	cube2->AddComponent(cube2_collision);


	//cube3 = new Penjin::GameObject("Cube3");
	////cube2->transform.scale = Penjin::Vector3(0.5f, 0.5f, 0.5f);
	//Penjin::StaticMeshComponent* cube3_staticMesh = new Penjin::StaticMeshComponent();
	//cube3_staticMesh->LoadMesh("Models/Cube");
	//cube3->AddComponent(cube3_staticMesh);

	//Penjin::CollisionComponent* cube3_collision = new Penjin::CollisionComponent(Penjin::Vector3(-1.2, 2.2, -1), 0);
	//cube3->AddComponent(cube3_collision);



	//cube4 = new Penjin::GameObject("Cube4");
	////cube1->transform.scale = Penjin::Vector3(0.5f, 0.5f, 0.5f);

	//Penjin::StaticMeshComponent* cube4_staticMesh = new Penjin::StaticMeshComponent();
	//cube4_staticMesh->LoadMesh("Models/Cube");
	//cube4_staticMesh->material->BaseColor = Penjin::Color(0, 1, 0, 1);
	//cube4->AddComponent(cube4_staticMesh);

	//Penjin::CollisionComponent* cube4_collision = new Penjin::CollisionComponent(Penjin::Vector3(0, 50, 0), 1);
	//cube4->AddComponent(cube4_collision);

	//cube5 = new Penjin::GameObject("Cube5");
	////cube1->transform.scale = Penjin::Vector3(0.5f, 0.5f, 0.5f);

	//Penjin::StaticMeshComponent* cube5_staticMesh = new Penjin::StaticMeshComponent();
	//cube5_staticMesh->LoadMesh("Models/Cube");
	//cube5_staticMesh->material->BaseColor = Penjin::Color(1, 0, 0, 1);
	//cube5->AddComponent(cube5_staticMesh);
	//Penjin::CollisionComponent* cube5_collision = new Penjin::CollisionComponent(Penjin::Vector3(0.5f, 60, 0), 4);
	//cube5->AddComponent(cube5_collision);
}

void Application3D::Shutdown()
{
	Application::Shutdown();
	Penjin::Log::Message("Shutting down...");
}

void Application3D::Update()
{
	Application::Update();
	//SDL_SetWindowTitle(GetWindow(), ("FPS " + std::to_string(Penjin::Time::GetFps()) + " ( " + std::to_string(Penjin::Time::GetDeltaTime()) + "ms )").c_str());

	cube1->Update();
	cube2->Update();
	//cube3->Update();
	//cube4->Update();
	//cube5->Update();

}

void Application3D::Draw()
{
	Application::Draw();
}

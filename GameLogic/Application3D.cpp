#include "Application3D.h"
#include <iostream>
#include <string>
#include <Times.h>
#include <Log.h>
#include <StaticMeshComponent.h>
#include <Color.h>
#include <ObjectLoader.h>
#include "RotationComponent.h"
#include "RotateAroundPointComponent.h"
#include "LookAtComponent.h"
#include "CameraMovement.h"


void LoadMesh(const char* filename) {

}

bool Application3D::Startup()
{
	if (!Application::Startup()) return false;

	Penjin::Log::Message("Starting...");

	camera = new Penjin::Camera(Penjin::Vector3(0, 1, -3), 60);
	camera->transform.rotation = Penjin::Vector3(0, 0, 0);

	CameraMovement* cameraMovement = new CameraMovement();
	camera->AddComponent(cameraMovement);


	
	Penjin::Mesh* meshArrow = Penjin::ObjectLoader::LoadObjModel("Models/Arrow.obj");
	Penjin::Mesh* meshPlate = Penjin::ObjectLoader::LoadObjModel("Models/Plate.obj");

	//Arrow
	arrow = new Penjin::GameObject("Arrow");
	arrow->transform.position = Penjin::Vector3(0, 1, 0);
	arrow->transform.rotation = Penjin::Vector3(90, 90, 90);
	arrow->transform.scale = Penjin::Vector3(0.2f, 0.2f, 0.2f);

	Penjin::StaticMeshComponent* arrow_staticMeshComponent = new Penjin::StaticMeshComponent();
	arrow_staticMeshComponent->LoadMesh("Models/Cube.obj");
	arrow_staticMeshComponent->material->LoadTexture("Images/WhitePixel.png");
	arrow_staticMeshComponent->material->LoadShader("Shader/Unlit.vert", "Shader/Unlit.frag");
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
	cube_x_staticMeshComponent->material->LoadShader("Shader/Unlit.vert", "Shader/Unlit.frag");
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
	cube_y_staticMeshComponent->material->LoadShader("Shader/Unlit.vert", "Shader/Unlit.frag");
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
	cube_z_staticMeshComponent->material->LoadShader("Shader/Unlit.vert", "Shader/Unlit.frag");
	cube_z_staticMeshComponent->drawWireframe = false;
	cube_z_staticMeshComponent->material->BaseColor = Penjin::Color(0, 0, 1);
	cubeZ->AddComponent(cube_z_staticMeshComponent);


	//ArrowX

	arrowX = new Penjin::Arrow("ArrowX");
	arrowX->transform.position = Penjin::Vector3(0.2f, 0, 0);
	arrowX->transform.rotation = Penjin::Vector3(0, 0, -90);	
	arrowX->transform.scale = Penjin::Vector3(0.2f, 0.2f, 0.2f);

	arrowX->color = Penjin::Color(1.0f, 0.0f, 0.0f);

	LookAtComponent* arrow_x_lookAtComponent = new LookAtComponent();
	arrow_x_lookAtComponent->lookAt = &arrow->transform;
	arrow_x_lookAtComponent->direction = LookAtComponent::Direction::RightVector;
	arrowX->AddComponent(arrow_x_lookAtComponent);

	//ArrowY
	arrowY = new Penjin::Arrow("ArrowY");
	arrowY->transform.position = Penjin::Vector3(0, 0.2f, 0);
	arrowY->transform.rotation = Penjin::Vector3(0, 0, 0);
	arrowY->transform.scale = Penjin::Vector3(0.2f, 0.2f, 0.2f);
	arrowY->color = Penjin::Color(0.0f, 1.0f, 0.0f);

	LookAtComponent* arrow_y_lookAtComponent = new LookAtComponent();
	arrow_y_lookAtComponent->lookAt = &arrow->transform;
	arrow_y_lookAtComponent->direction = LookAtComponent::Direction::UpVector;
	arrowY->AddComponent(arrow_y_lookAtComponent);


	//ArrowZ
	arrowZ = new Penjin::Arrow("ArrowZ");
	arrowZ->transform.position = Penjin::Vector3(0, 0, 0.2f);
	arrowZ->transform.rotation = Penjin::Vector3(90, 0, 0);
	arrowZ->transform.scale = Penjin::Vector3(0.2f, 0.2f, 0.2f);
	arrowZ->color = Penjin::Color(0.0f, 0.0f, 1.0f);

	LookAtComponent* arrow_z_lookAtComponent = new LookAtComponent();
	arrow_z_lookAtComponent->lookAt = &arrow->transform;
	arrow_z_lookAtComponent->direction = LookAtComponent::Direction::ForwardVector;
	arrowZ->AddComponent(arrow_z_lookAtComponent);
	

	weirdCube = new Penjin::GameObject("TestObject");
	weirdCube->transform.position = Penjin::Vector3(0, 0, 0);
	//weirdCube->transform.scale = Penjin::Vector3(0.5f, 0.5f, 0.5f);

	//Cube
	Penjin::StaticMeshComponent* weirdCube_staticMeshComponent = new Penjin::StaticMeshComponent();
	weirdCube_staticMeshComponent->LoadMesh("Models/WeirdCube.obj");
	weirdCube_staticMeshComponent->material->BaseColor = Penjin::Color(0.7f, 0.7f, 0.7f, 1.0f);
	weirdCube_staticMeshComponent->drawWireframe = false;
	weirdCube->AddComponent(weirdCube_staticMeshComponent);

	weirdCubeTop = new Penjin::GameObject("TestObject");
	weirdCubeTop->transform.position = Penjin::Vector3(0, 2, 0);
	weirdCubeTop->transform.rotation = Penjin::Vector3(180, 0, 0);
	//weirdCube->transform.scale = Penjin::Vector3(0.5f, 0.5f, 0.5f);

	//Cube
	Penjin::StaticMeshComponent* weirdCubeTop_staticMeshComponent = new Penjin::StaticMeshComponent();
	weirdCubeTop_staticMeshComponent->LoadMesh("Models/WeirdCube.obj");
	weirdCubeTop_staticMeshComponent->material->BaseColor = Penjin::Color(0.7f, 0.7f, 0.7f, 1.0f);
	weirdCubeTop_staticMeshComponent->drawWireframe = true;
	weirdCubeTop->AddComponent(weirdCubeTop_staticMeshComponent);
		
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
	weirdCube->Update();
	weirdCubeTop->Update();
	
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

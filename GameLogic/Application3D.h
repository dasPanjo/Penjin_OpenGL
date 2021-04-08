#pragma once
#include <Application.h>
#include <GameObject.h>
#include <Arrow.h>

class Application3D 
	: public Penjin::Application
{
public:
	static void Start() { DeleteInstance(); Instance = new Application3D(); Instance->Run("Game Logic", 1280, 720, false); }
	static void DeleteInstance() { if (Instance) { delete Instance; } }

	virtual bool Startup();
	virtual void Shutdown();
	virtual void Update();
	virtual void Draw();


private:

	Penjin::GameObject* arrow = nullptr;

	Penjin::GameObject* cubeX = nullptr;
	Penjin::GameObject* cubeY = nullptr;
	Penjin::GameObject* cubeZ = nullptr;

	Penjin::Arrow* arrowX = nullptr;
	Penjin::Arrow* arrowY = nullptr;
	Penjin::Arrow* arrowZ = nullptr;

	Penjin::GameObject* weirdCube = nullptr;
	Penjin::GameObject* weirdCubeTop = nullptr;
};


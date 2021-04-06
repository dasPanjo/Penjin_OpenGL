#pragma once
#include <Application.h>
#include <GameObject.h>

class Application3D 
	: public Penjin::Application
{
public:
	static void Start() { DeleteInstance(); Instance = new Application3D(); Instance->Run("Game Logic", 800, 600, false); }
	static void DeleteInstance() { if (Instance) { delete Instance; } }

	virtual bool Startup();
	virtual void Shutdown();
	virtual void Update();
	virtual void Draw();


private:

	Penjin::GameObject* cube = nullptr;
};


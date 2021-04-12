#pragma once
#include <Application.h>
#include <GameObject.h>
#include <Arrow.h>

class Application3D 
	: public Penjin::Application
{
public:
	
	virtual ~Application3D() override;

	static void Start() { DeleteInstance(); Instance = new Application3D(); Instance->Run("Game Logic", 1280, 720, false); }
	static void DeleteInstance() { if (Instance) { delete Instance; } }

	virtual bool Awake() override;
	virtual void Startup() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw() override;

protected:
	Penjin::GameObject* cube1;
	Penjin::GameObject* cube2;
	Penjin::GameObject* cube3;
	Penjin::GameObject* cube4;
	Penjin::GameObject* cube5;
	Penjin::GameObject* cube6;
	Penjin::GameObject* cube7;


};


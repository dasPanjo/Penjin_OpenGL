#include "GameObject.h"
#include "Log.h"

Penjin::GameObject::GameObject()
	:GameObject("GameObject")
{
}

Penjin::GameObject::GameObject(std::string name)
{
	this->name = name;
}

Penjin::GameObject::~GameObject()
{
	for (size_t i = 0; i < components.size(); i++)
	{
		if (components[i])
			delete components[i];
	}
	components.clear();
}

void Penjin::GameObject::Start()
{
}

void Penjin::GameObject::Update()
{
	for (size_t i = 0; i < components.size(); i++)
	{
		if (components[i])
			components[i]->Update();
	}
}

void Penjin::GameObject::AddComponent(Component* component)
{
	if (!component) {
		Log::Error("GameObject '" + this->name + "': AddComponent was called with nullptr");
		return;
	}
	//Log::Message("Added " + name);
	components.push_back(component);
	component->SetGameObject(this);
	component->Start();
}

void Penjin::GameObject::RemoveComponent(Component* component)
{
	for (size_t i = components.size()-1; i >= 0; i--)
	{
		if (components[i] && components[i] == component)
			components.erase(components.begin() + i);
	}
}

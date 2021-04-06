#include <iostream>

#define SDL_MAIN_HANDLED

#include <Log.h>
#include "Application3D.h"

int main() {
	Penjin::Log::LogLevelFile = Penjin::LogLevel::Info;
	Application3D::Start();
	Application3D::DeleteInstance();
	return 0;
}
#include "Times.h"

namespace Penjin {
	float Time::DeltaTime = 0;
	float Time::CurrentTime = 0;
	uint32_t Time::Fps = 0;

	uint64_t Time::perfCounterFrequency = SDL_GetPerformanceFrequency();
	uint64_t Time::lastCounter = SDL_GetPerformanceCounter();

	std::vector<float> Time::fps_cache;

	void Time::Tick()
	{
		uint64_t endCounter = SDL_GetPerformanceCounter();
		uint64_t counterElapsed = endCounter - lastCounter;
		DeltaTime = ((float)counterElapsed) / ((float)perfCounterFrequency);
		CurrentTime = ((float)endCounter) / ((float)perfCounterFrequency);
		Fps = (uint32_t)((float)perfCounterFrequency / (float)counterElapsed);

		lastCounter = endCounter;
	}

}
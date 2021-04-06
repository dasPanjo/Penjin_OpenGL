#pragma once
#include <SDL.h>
namespace Penjin {

	class Time
	{
	public:
		/// <summary>Returns the DeltaTime in seconds</summary>
		static float GetDeltaTime() { return DeltaTime; }

		/// <summary>Returns the current time in seconds</summary>
		static float GetCurrentTime() { return CurrentTime; }

		/// <summary>Returns the current frames per second</summary>
		static uint32_t GetFps() { return Fps; }

		/// <summary>Will update the times</summary>
		static void Tick();

	private:
		/// <summary>Delta time in seconds</summary>
		static float DeltaTime;

		/// <summary>Current time in seconds</summary>
		static float CurrentTime;

		/// <summary>Current frames per second</summary>
		static uint32_t Fps;

		/// <summary>Peformance counter frequency</summary>
		static uint64_t perfCounterFrequency;

		/// <summary>Timestamp of the last frame</summary>
		static uint64_t lastCounter;
	};

}

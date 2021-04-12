#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include "Camera.h"
#include "Skybox.h"
#include "DynamicWorld.h"

namespace Penjin
{
	/// <summary>Mainframe for the Engine</summary>
	class Application
	{
	public:
		/// <summary>Empty constructor</summary>
		Application();

		/// <summary>Destructor</summary>
		virtual ~Application();

		/// <summary>Starts the main loop</summary>
		/// <param name="title">Window title</param>
		/// <param name="width">Window width</param>
		/// <param name="height">Window height</param>
		/// <param name="fullscreen">Window fullscreen param (true = fullscreen)</param>
		void Run(const char* title, int width, int height, bool fullscreen);

		/// <summary>Will initialize all the neccessarry dependencies</summary>
		virtual bool Awake() { return true; }

		/// <summary>Will be called before the first frame is drawn</summary>
		virtual void Startup() {}
		/// <summary>Will be called when the window is closed</summary>
		virtual void Shutdown() {}
		/// <summary>Will be called every frame</summary>
		virtual void Update();
		/// <summary>Will be called every frame</summary>
		virtual void Draw();



		/**[ Getter & Setter ]**/
		static Application* GetInstance() { return Instance; }

		/// <summary>Quits the game</summary>
		void quit() { m_gameOver = true; }
		/// <summary>Returns whether or not the main loop is finished</summary>
		bool IsGameOver() const { return m_gameOver; }

		/// <summary>Returns a handle to the window</summary>
		SDL_Window* GetWindow() const { return window; }
		/// <summary>Returns the SDL_GLContext</summary>
		SDL_GLContext GetGLContext() const { return glContext; }

		/// <summary>Returns a handle to the main camera</summary>
		Camera* GetCamera() const { return camera; }
		void SetCamera(Camera* camera);

		Skybox* GetSkybox() const { return skybox; }
		DynamicWorld* GetDynamicWorld() const { return dynamicWorld; }


	protected:
		/// <summary>Returns a handle to the active Application</summary>
		static Application* Instance;

		/// <summary>Will be true when the gameloop is ended</summary>
		bool m_gameOver;

		/// <summary>Will create a SDL window</summary>
		/// <param name="title">The title of the window</param>
		/// <param name="width">The width of the window</param>
		/// <param name="height">The height of the window</param>
		/// <param name="fullscreen">Window fullscreen param (true = fullscreen)</param>
		/// <returns>true if the window was createds</returns>
		virtual bool CreateWindow(const char* title, int width, int height, bool fullscreen);

		/// <summary>Will destroy the window</summary>
		virtual void DestroyWindow();


		/// <summary>Handle to the window</summary>
		SDL_Window* window;
		/// <summary>The SDL_GLContext</summary>
		SDL_GLContext glContext;


		/// <summary>The active camera</summary>
		Camera* camera;
		Skybox* skybox;
		DynamicWorld* dynamicWorld;
	};
}
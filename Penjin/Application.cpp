#include "Application.h"
#include <iostream>
#include "Renderer.h"
#include "Times.h"
#include "Log.h"

namespace Penjin
{
	void GLAPIENTRY openGLDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam) {
		if (id == 131218)// NVIDIA: "shader will be recompiled due to GL state mismatches"
			return;

		std::string errorMessage("[OpenGL Message] " + std::string(message) + " (id: " + std::to_string(id) + ")");
		if (severity != GL_DEBUG_SEVERITY_NOTIFICATION)
			Log::Error(errorMessage);
		/*else
			Log::Message(errorMessage);*/
	}

	Application* Application::Instance = nullptr;

	Application::Application()
		: m_gameOver(false),
		glContext(nullptr),
		window(nullptr),
		camera(nullptr)
	{
	}

	Application::~Application()
	{
	}

	void Application::Run(const char* title, int width, int height, bool fullscreen)
	{
		if (CreateWindow(title, width, height, fullscreen) && Startup())
		{
			Renderer::Init();

			while (!m_gameOver) {

				glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
				Time::Tick();

				Update();
				Draw();


				SDL_GL_SwapWindow(window);
				SDL_Event event;
				while (SDL_PollEvent(&event)) {
					switch (event.type) {
					case SDL_QUIT:
						m_gameOver = true;
						break;
					}
				}
			}
		}
		Shutdown();
		DestroyWindow();
	}

	void Application::Update()
	{
	}

	void Application::Draw()
	{
		Renderer::Render();
	}


	bool Application::CreateWindow(const char* title, int width, int height, bool fullscreen)
	{

		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
#ifdef _DEBUG
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
#endif

		Uint32 windowFlags = SDL_WINDOW_OPENGL;
		if (fullscreen)
			windowFlags = windowFlags | SDL_WINDOW_FULLSCREEN;

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, windowFlags);
		glContext = SDL_GL_CreateContext(window);
		GLenum glewError = glewInit();
		if (glewError != GLEW_OK) {
			Log::Critical("GLEW-error: " + std::string((char*)glewGetErrorString(glewError)));
			return false;
		}

		Log::Message("OpenGL vesion: " + std::string((char*)glGetString(GL_VERSION)));

#ifdef _DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glDebugMessageCallback(openGLDebugCallback, 0);
#endif

		return true;
	}

	void Application::DestroyWindow()
	{
		SDL_Quit();
	}

}
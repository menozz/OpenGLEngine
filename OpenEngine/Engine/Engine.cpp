#include "Engine.h"

int Engine::SCR_H = 1024;
int Engine::SCR_W = 768;

GLFWwindow* Engine::window = nullptr;

Engine::Engine()
{

}

Engine::~Engine()
{

}

bool Engine::Initialize(const char* wndTitle)
{
	if (!glfwInit())
	{
		cout << "Error initializing GLFW" << endl;
		return false;
	}

	window = glfwCreateWindow(SCR_W, SCR_H, wndTitle, nullptr, nullptr);
	if (window == nullptr)
	{
		cout << "Error creating window" << endl;
		return false;
	}

	// GLFW

	glfwMakeContextCurrent(window);
	int w, h;
	glfwGetFramebufferSize(window, &w, &h);
	glfwSwapInterval(1);

	const auto mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	const auto xPos = (mode->width - SCR_W) / 2;
	const auto yPos = (mode->height - SCR_H) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	// GL
	glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -10, 10);
	glDepthRange(-10, 10);
	
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

void Engine::Update()
{
	glfwPollEvents();
}

void Engine::Render()
{
	glClearColor(0, 1, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwSwapBuffers(window);
}


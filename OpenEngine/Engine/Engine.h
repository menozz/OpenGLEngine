#ifndef ENGINE
#define ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include "iostream"
using namespace std;

class Engine
{
	static GLFWwindow* window;

public:

	static int SCR_W;
	static int SCR_H;

	Engine();
	~Engine();

	bool Initialize(const char *wndTitle);

	void Update();
	void BeginRender();
	void EndRender();
};

#endif

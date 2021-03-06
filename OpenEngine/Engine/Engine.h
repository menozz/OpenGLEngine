#ifndef ENGINE
#define ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include "iostream"
using namespace std;

class Engine
{
	static GLFWwindow* window;
	static float dt;
	float lastTime;

public:

	static int SCR_W;
	static int SCR_H;
	static float GetDT();

	Engine();
	~Engine();

	bool Initialize(const char *wndTitle);

	void Update();
	void BeginRender();
	void EndRender();
};

#endif

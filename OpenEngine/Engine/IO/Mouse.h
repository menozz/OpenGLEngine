#ifndef MOUSE
#define MOUSE

#include "GLFW/glfw3.h"

class Mouse
{
	static double x, y;
	static bool buttons[];
	static bool buttonsDown[];
	static bool buttonsUp[];

public:

	static void MousePosCallBack(GLFWwindow* window, double x, double y);
	static void MouseButtonCallBack(GLFWwindow* window, int button, int action, int mods);
	
	static double GetMouseX();
	static double GetMouseY();

	static bool ButtonDown(int button);
	static bool ButtonUp(int button);
	static bool Button(int button);
};

#endif


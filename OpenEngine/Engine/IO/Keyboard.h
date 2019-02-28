#ifndef KEYBOARD
#define KEYBOARD

#include "GLFW/glfw3.h"

class Keyboard
{
	static bool keys[];
	static bool keysDown[];
	static bool keysUp[];

public:

	static void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
	static bool KeyDown(int key);
	static bool KeyUp(int key);
	static bool Key(int key);
};

#endif KEYBOARD

#include "Mouse.h"

double Mouse::x = 0;
double Mouse::y = 0;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { false };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { false };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { false };

void Mouse::MousePosCallBack(GLFWwindow* window, double _x, double _y)
{
	int w, h;
	glfwGetFramebufferSize(window, &w, &h);

	Mouse::x = _x;
	Mouse::y = h - _y;
}

void Mouse::MouseButtonCallBack(GLFWwindow* window, int button, int action, int mods)
{
	if (button < 0) return;

	if (action != GLFW_RELEASE && !buttons[button])
	{
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}

	if (action == GLFW_RELEASE && buttons[button])
	{
		buttonsDown[button] = false;
		buttonsUp[button] = true;
	}

	buttons[button] = action != GLFW_RELEASE;

}

double Mouse::GetMouseX()
{
	return x;
}

double Mouse::GetMouseY()
{
	return y;
}

bool Mouse::Button(int button)
{
	return buttons[button];
}

bool Mouse::ButtonDown(int button)
{
	const auto b = buttonsDown[button];
	buttonsDown[button] = false;
	return b;
}

bool Mouse::ButtonUp(int button)
{
	const bool b = buttonsUp[button];
	buttonsUp[button] = false;
	return b;
}


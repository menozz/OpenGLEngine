#include "InputManager.h"

#define ROTSPEED 100

InputManager::InputManager(Flapper* _flapper)
{
	flapper = _flapper;
}

void InputManager::Update()
{
	if (Keyboard::Key(GLFW_KEY_SPACE) || Mouse::Button(GLFW_MOUSE_BUTTON_LEFT))
	{
		//flapper->GetRB().AddForce({ 0,20,0 });
		flapper->Flap();
	}
	//flapper->GetSprite().MoveTo({ (float)Mouse::GetMouseX(), (float)Mouse::GetMouseY() ,0});
	/*if (Keyboard::Key(GLFW_KEY_W))
	{
		flapper->GetRB().AddForce({ 0,20,0 });
	}

	if (Keyboard::Key(GLFW_KEY_S))
	{
		flapper->GetRB().AddForce({ 0,-20,0 });
	}

	if (Keyboard::Key(GLFW_KEY_A))
	{
		flapper->GetRB().AddForce({ -200,0,0 });
	}

	if (Keyboard::Key(GLFW_KEY_D))
	{
		flapper->GetRB().AddForce({ 200,0,0 });
	}*/
}


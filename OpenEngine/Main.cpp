#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

#define ROTSPEED 100

int main()
{
	auto engine = Engine();
	if (engine.Initialize("Window Title"))
	{
		auto sprite = Sprite("Assets/Art/7.png", Vector3());
		sprite.SetScale(0.25f);
		while (true)
		{
			engine.Update();
			sprite.Update();

			if (Mouse::Button(GLFW_MOUSE_BUTTON_RIGHT))
			{
				sprite.RotateBy(ROTSPEED);
			}

			if (Mouse::Button(GLFW_MOUSE_BUTTON_LEFT))
			{
				sprite.RotateBy(-ROTSPEED);
			}

			if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
			{
				sprite.RotateTo(0);
			}

			if (Keyboard::Key(GLFW_KEY_W))
			{
				sprite.MoveUp();
			}

			if (Keyboard::Key(GLFW_KEY_S))
			{
				sprite.MoveDown();
			}

			if (Keyboard::Key(GLFW_KEY_A))
			{
				sprite.MoveLeft();
			}

			if (Keyboard::Key(GLFW_KEY_D))
			{
				sprite.MoveRight();
			}

			engine.BeginRender();
			sprite.Render();
			engine.EndRender();
		}
	}

	return 0;
}

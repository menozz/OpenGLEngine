#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "Flapper/Flapper.h"

#define ROTSPEED 100


int main()
{
	auto engine = Engine();
	if (engine.Initialize("Window Title"))
	{
		auto sprite = Sprite("Assets/Art/7.png", Vector3());
		sprite.SetScale(0.25f);

		Flapper player(sprite);

		while (true)
		{
			engine.Update();
			player.Update();

			if (Mouse::Button(GLFW_MOUSE_BUTTON_RIGHT))
			{
				player.GetSprite().RotateBy(ROTSPEED);
			}

			if (Mouse::Button(GLFW_MOUSE_BUTTON_LEFT))
			{
				player.GetSprite().RotateBy(-ROTSPEED);
			}

			if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
			{
				player.GetSprite().RotateTo(0);
			}

			if (Keyboard::Key(GLFW_KEY_W))
			{
				player.GetRB().AddForce({ 0,20,0 });
			}

			if (Keyboard::Key(GLFW_KEY_S))
			{
				player.GetRB().AddForce({ 0,-20,0 });
			}

			if (Keyboard::Key(GLFW_KEY_A))
			{
				player.GetRB().AddForce({ -200,0,0 });
			}

			if (Keyboard::Key(GLFW_KEY_D))
			{
				player.GetRB().AddForce({ 200,0,0 });
			}

			engine.BeginRender();
			player.Render();
			engine.EndRender();
		}
	}

	return 0;
}

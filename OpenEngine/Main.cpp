#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Flapper/Flapper.h"
#include "Flapper/InputManager.h"

int main()
{
	auto engine = Engine();
	if (engine.Initialize("Window Title"))
	{
		auto sprite = Sprite("Assets/Art/7.png", Vector3((float)Engine::SCR_W/2, (float)Engine::SCR_H / 2, 0));
		sprite.SetScale(0.25f);

		Flapper player(sprite);
		InputManager manager(&player);
		while (true)
		{
			engine.Update();
			player.Update();
			manager.Update();
			engine.BeginRender();
			player.Render();
			engine.EndRender();
		}
	}

	return 0;
}

#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Flapper/Flapper.h"
#include "Flapper/InputManager.h"

int main()
{
	auto engine = Engine();
	if (engine.Initialize("Window Title"))
	{
		auto sprite = Sprite("Assets/Art/7.png", Vector3(Engine::SCR_W/2, Engine::SCR_H / 2, 0));
		sprite.SetScale(0.25f);

		auto sprite2 = Sprite("Assets/Art/7.png", Vector3(Engine::SCR_W / 2.40, Engine::SCR_H / 2.40, 0));
		sprite2.SetScale(0.25f);
		//sprite2.MoveTo(Vector3(Engine::SCR_W / 2.5, Engine::SCR_H / 2.5, 0));
		Flapper player(sprite);
		Flapper player2(sprite2);


		InputManager manager(&player);

		while (true)
		{
			engine.Update();
			
			player.Update();
			player2.Update();
			
			manager.Update();
			bool isColliding = Rigidbody::IsColliding(player.GetRB(), player2.GetRB());
			cout << (isColliding ? "COLLIDING!!!" : "....") << endl;
			engine.BeginRender();

			player.Render();
			player2.Render();
			
			engine.EndRender();
		}
	}

	return 0;
}

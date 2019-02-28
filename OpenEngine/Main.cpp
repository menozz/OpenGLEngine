#include "cstdlib"
#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"

int main()
{
	system("pause");

    auto engine = Engine();
	if (engine.Initialize("Window Title"))
	{
		auto sprite = Sprite("Assets/Art/7.png", 0, 0);
		while (true)
		{
			engine.Update();
			sprite.Update();

			sprite.SetPos((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());

			engine.BeginRender();
			sprite.Render();
			engine.EndRender();
		}
	}

	system("pause");
	return 0;
}

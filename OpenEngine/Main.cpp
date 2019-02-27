#include "cstdlib"
#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"

int main()
{
	system("pause");

    auto engine = Engine();
	if (engine.Initialize("Window Title"))
	{
		auto sprite = Sprite("Assets/Art/7.png", -100, -100);
		while (true)
		{
			engine.Update();
			sprite.Update();

			engine.BeginRender();
			sprite.Render();
			engine.EndRender();
		}
	}

	system("pause");
	return 0;
}

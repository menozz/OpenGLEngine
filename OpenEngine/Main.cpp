#include "cstdlib"
#include "Engine/Engine.h"


int main()
{
	system("pause");

	auto engine = new Engine();
	if (engine->Initialize("Window Title"))
	{
		while (true)
		{
			engine->Update();
			engine->Render();
		}
	}

	system("pause");
	delete engine;
	return 0;
}

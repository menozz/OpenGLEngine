#ifndef FLAPPER
#define FLAPPER
#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigibody.h"

#define FRICTION 0.9f
#define GRAVITY -10.0f

class Flapper
{
	Sprite sprite;
	Rigidbody rb;

public:
	Flapper();
	Flapper(Sprite _sprite);
	
	void Update();
	void Render();

	Sprite& GetSprite();
	Rigidbody& GetRB();
	void Flap();
};

#endif

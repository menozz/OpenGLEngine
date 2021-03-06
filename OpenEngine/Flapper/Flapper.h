﻿#ifndef FLAPPER
#define FLAPPER
#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigibody.h"

#define FRICTION 0.8f
#define GRAVITY -15.0f
#define VELOCITY 400
#define MAXANGLE 30

class Flapper
{
	Sprite sprite;
	Rigidbody rb;

	float maxRot;
	float minRot;
	float flapForce;

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

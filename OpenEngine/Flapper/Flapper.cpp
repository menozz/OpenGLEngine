﻿#include "Flapper.h"

Flapper::Flapper()
{
	
}

Flapper::Flapper(Sprite _sprite)
{
	sprite = _sprite;
	rb.Initialize(FRICTION, GRAVITY, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize());
}

void Flapper::Update()
{
	sprite.Update();
	rb.Update();
}

void Flapper::Render()
{
	sprite.Render();
	rb.Render({});
}

Sprite& Flapper::GetSprite()
{
	return sprite;
}

Rigidbody& Flapper::GetRB()
{
	return rb;
}






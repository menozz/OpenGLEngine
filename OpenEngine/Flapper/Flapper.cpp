#include "Flapper.h"
#include "../Engine/Engine.h"

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
	sprite.RotateBy(100 * Engine::GetDT());
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

void Flapper::Flap()
{
	rb.AddForce({ 0, 50, 0 });
}






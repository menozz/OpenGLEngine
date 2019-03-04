#include "Flapper.h"
#include "../Engine/Engine.h"

Flapper::Flapper()
{
	flapForce = VELOCITY;
	maxRot = MAXANGLE;
	minRot = -maxRot;
}

Flapper::Flapper(Sprite _sprite) : Flapper()
{
	sprite = _sprite;
	Rect boundingRect = Rect();
	boundingRect.SetSize(*sprite.GetSize() * *sprite.GetScale());
	rb.Initialize(FRICTION, GRAVITY, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize(), boundingRect);
}

void Flapper::Update()
{
	sprite.Update();
	rb.Update();

	float yVal = rb.GetVel().y;
	if (flapForce == 0)
	{
		cout << "Error flapping" << endl;
		flapForce = VELOCITY;
	}

	float newRot = (maxRot / flapForce) * yVal;
	//sprite.RotateTo(newRot);
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
	/*rb.SetVel({ 0, flapForce, 0 });
	sprite.RotateTo(maxRot);*/
	sprite.RotateBy(10);
}






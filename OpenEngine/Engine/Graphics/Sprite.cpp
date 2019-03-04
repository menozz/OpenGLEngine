#include "Sprite.h"
#include "../Engine.h"

#define MOVESPEED 20

Sprite::Sprite()
{
	pos = {};
	texture = {};
	rot = 0;
	speed = MOVESPEED;
	size = {};
	scale = { 1 };
}

Sprite::Sprite(string imagePath) : Sprite()
{
	texture = Texture(imagePath);
	size = { (float)texture.GetWidth(), (float)texture.GetHeight(), 1 };
}

Sprite::Sprite(string imagePath, Vector3 v) : Sprite()
{
	texture = Texture(imagePath);
	pos = v;
}

void Sprite::Update()
{
}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	// TRANSLATE->ROTATE->SCALE
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);

	// Rendering
	glColor4f(1, 1, 1, 1);

	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0); glVertex2i(-texture.GetWidth() / 2, -texture.GetHeight() / 2);
		glTexCoord2f(1, 0); glVertex2i(texture.GetWidth() / 2, -texture.GetHeight() / 2);
		glTexCoord2f(1, 1); glVertex2i(texture.GetWidth() / 2, texture.GetHeight() / 2);
		glTexCoord2f(0, 1); glVertex2i(-texture.GetWidth() / 2, texture.GetHeight() / 2);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::MoveTo(Vector3 v)
{
	pos = v;
}

void Sprite::MoveBy(Vector3 v)
{
	pos += (v * Engine::GetDT());
}

void Sprite::MoveLeft()
{
	pos.x -= speed * Engine::GetDT();
}

void Sprite::MoveRight()
{
	pos.x += speed * Engine::GetDT();
}

void Sprite::MoveUp()
{
	pos.y += speed * Engine::GetDT();
}

void Sprite::MoveDown()
{
	pos.y -= speed * Engine::GetDT();
}

void Sprite::RotateTo(float x)
{
	this->rot = x;
}

void Sprite::RotateBy(float x)
{
	this->rot += (x * Engine::GetDT());
}

void Sprite::SetScale(float x)
{
	scale = x;
}

void Sprite::SetScale(Vector3 v)
{
	scale = v;
}

void Sprite::SpeedTo(float x)
{
	speed = x;
}

void Sprite::SpeedBy(float x)
{
	speed += x;
}

Vector3* Sprite::GetPos()
{
	return &pos;
}

float* Sprite::GetRot()
{
	return &rot;
}

Vector3* Sprite::GetScale()
{
	return &scale;
}

Vector3* Sprite::GetSize()
{
	return &size;
}




#include "Sprite.h"
#include "../Engine.h"

#define MOVESPEED 200

Sprite::Sprite()
{
	pos = Vector3();
	texture = Texture();
	rot = 0;
	speed = MOVESPEED;
}

Sprite::Sprite(string imagePath)
{
	texture = Texture(imagePath);
	pos = Vector3();
	rot = 0;
	speed = MOVESPEED;
}

Sprite::Sprite(string imagePath, Vector3 v)
{
	texture = Texture(imagePath);
	pos = v;
	rot = 0;
	speed = MOVESPEED;
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
	glTexCoord2i(0, 0); glVertex2i(0, 0);
	glTexCoord2i(1, 0); glVertex2i(texture.GetWidth(), 0);
	glTexCoord2i(0, 1); glVertex2i(0, texture.GetHeight());
	glTexCoord2i(1, 1); glVertex2i(texture.GetWidth(), texture.GetHeight());
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

#include "Sprite.h"
#include "../Engine.h"

Sprite::Sprite()
{
	yPos = xPos = 0;
	texture = Texture();
	rot = 0;
	speed = 100;
}

Sprite::Sprite(string imagePath)
{
	texture = Texture(imagePath);
	yPos = xPos = 0;
	rot = 0;
	speed = 100;
}

Sprite::Sprite(string imagePath, float xPos, float yPos)
{
	texture = Texture(imagePath);
	this->xPos = xPos;
	this->yPos = yPos;
	rot = 0;
	speed = 100;
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
	glTranslatef(xPos, yPos, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(xScale, yScale, 1);

	// Rendering
	glColor4f(1, 1, 1, 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(0, 0);
	glTexCoord2f(1, 0); glVertex2f(texture.GetWidth(), 0);
	glTexCoord2f(0, 1); glVertex2f(0, texture.GetHeight());
	glTexCoord2f(1, 1); glVertex2f(texture.GetWidth(), texture.GetHeight());
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::MoveTo(float x, float y)
{
	xPos = x;
	yPos = y;
}

void Sprite::MoveBy(float x, float y)
{
	xPos += x * Engine::GetDT();
	yPos += y * Engine::GetDT();
}

void Sprite::MoveLeft()
{
	xPos -= speed * Engine::GetDT();
}

void Sprite::MoveRight()
{
	xPos += speed * Engine::GetDT();
}

void Sprite::MoveUp()
{
	yPos += speed * Engine::GetDT();
}

void Sprite::MoveDown()
{
	yPos -= speed * Engine::GetDT();
}


void Sprite::RotateTo(float rot)
{
	this->rot = rot;
}

void Sprite::RotateBy(float rot)
{
	this->rot += (rot * Engine::GetDT());
}

void Sprite::SetScale(float x)
{
	xScale = yScale = x;
}

void Sprite::SetScale(float x, float y)
{
	xScale = x;
	yScale = y;
}

void Sprite::SpeedTo(float x)
{
	speed = x;
}

void Sprite::SpeedBy(float x)
{
	speed += x;
}

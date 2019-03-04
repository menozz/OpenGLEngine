#include "Rigibody.h"
#include "../Engine.h"

Rigidbody::Rigidbody()
{
	friction = 1;
	gravity = 0;
}

void Rigidbody::Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size)
{
	friction = _friction;
	gravity = _gravity;

	pos = _pos;
	rot = _rot;
	scale = _scale;
	size = _size;
}

void Rigidbody::Update()
{
	vel.x *= friction;
	vel.y += gravity;

	*pos += vel * Engine::GetDT();
	//vel = { 0 };
}

void Rigidbody::Render(Vector3 c)
{
	glLoadIdentity();
	glTranslatef(pos->x, pos->y, pos->z);
	glRotatef(*rot, 0, 0, 1);

	glColor4f(c.x, c.y, c.z, 1);
	glBegin(GL_LINES);
	{
		float x, y;
		x = size->x / 2;
		y = size->y / 2;
		
		glVertex2f(-x, -y);
		glVertex2f(x, -y);

		glVertex2f(x, -y);
		glVertex2f(x, y);

		glVertex2f(x, y);
		glVertex2f(-x, y);

		glVertex2f(-x, y);
		glVertex2f(-x, -y);
	}
	glEnd();
}

void Rigidbody::AddForce(Vector3 f)
{
	vel += f;
}

Vector3 Rigidbody::GetVel()
{
	return vel;
}

void Rigidbody::SetVel(Vector3 _vel)
{
	vel = _vel;
}






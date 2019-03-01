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
		glVertex2f(0, 0);
		glVertex2f(size->x, 0);
		
		glVertex2f(size->x, 0); 
		glVertex2f(size->x, size->y);

		glVertex2f(size->x, size->y);
		glVertex2f(0, size->y);

		glVertex2f(0, size->y);
		glVertex2i(0, 0);
	}
	glEnd();
}

void Rigidbody::AddForce(Vector3 f)
{
	vel += f;
}






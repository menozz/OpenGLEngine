#include "Rigibody.h"
#include "../Engine.h"
#include "../Math/Math.h"
#include <vector>

bool Rigidbody::IsColliding(const Rigidbody& rbA, const Rigidbody& rbB)
{
	Rect rcA = rbA.bounding;
	Rect rcB = rbB.bounding;

	Vector3 aUR = rcA.vUR + *rbA.pos;
	Vector3 aUL = rcA.vUL + *rbA.pos;
	Vector3 aLR = rcA.vLR + *rbA.pos;
	Vector3 aLL = rcA.vLL + *rbA.pos;

	Vector3 bUR = rcB.vUR + *rbB.pos;
	Vector3 bUL = rcB.vUL + *rbB.pos;
	Vector3 bLR = rcB.vLR + *rbB.pos;
	Vector3 bLL = rcB.vLL + *rbB.pos;

	float aMax = 0;
	float aMin = 0;
	float bMax = 0;
	float bMin = 0;

	/*Vector3 axis1 = rcA.vUR - rcA.vUL;
	Vector3 axis2 = rcA.vUR - rcA.vLR;
	Vector3 axis3 = rcB.vUL - rcB.vLL;
	Vector3 axis4 = rcB.vUL - rcB.vUR;*/
	Vector3 axis1 = aUR - aUL;
	Vector3 axis2 = aUR - aLR;
	Vector3 axis3 = bUL - bLL;
	Vector3 axis4 = bUL - bUR;

	vector<Vector3> axes;
	axes.push_back(axis1);
	axes.push_back(axis2);
	axes.push_back(axis3);
	axes.push_back(axis4);

	for (unsigned int i = 0; i < axes.size(); i++)
	{
		Vector3 paUR = Vector3::Project(aUR, axes[i]);
		Vector3 paUL = Vector3::Project(aUL, axes[i]);
		Vector3 paLR = Vector3::Project(aLR, axes[i]);
		Vector3 paLL = Vector3::Project(aLL, axes[i]);
				
		Vector3 pbUR = Vector3::Project(bUR, axes[i]);
		Vector3 pbUL = Vector3::Project(bUL, axes[i]);
		Vector3 pbLR = Vector3::Project(bLR, axes[i]);
		Vector3 pbLL = Vector3::Project(bLL, axes[i]);

		float aURs = Vector3::Dot(paUR, axes[i]);
		float aULs = Vector3::Dot(paUL, axes[i]);
		float aLRs = Vector3::Dot(paLR, axes[i]);
		float aLLs = Vector3::Dot(paLL, axes[i]);
								  
		float bURs = Vector3::Dot(pbUR, axes[i]);
		float bULs = Vector3::Dot(pbUL, axes[i]);
		float bLRs = Vector3::Dot(pbLR, axes[i]);
		float bLLs = Vector3::Dot(pbLL, axes[i]);

		vector<float> aV;
		aV.push_back(aURs);
		aV.push_back(aULs);
		aV.push_back(aLRs);
		aV.push_back(aLLs);
		aMin = Math::Min(aV);
		aMax = Math::Max(aV);

		vector<float> bV;
		bV.push_back(bURs);
		bV.push_back(bULs);
		bV.push_back(bLRs);
		bV.push_back(bLLs);
		bMin = Math::Min(bV);
		bMax = Math::Max(bV);

		if (bMin <= aMax && bMax >= aMin)
		{
			
		}
		else
		{
			return false;
		}
	}

	return true;
}

Rigidbody::Rigidbody()
{
	friction = 1;
	gravity = 0;
}

void Rigidbody::Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size, Rect _bounding)
{
	friction = _friction;
	gravity = _gravity;
	lastRot = *_rot;
	pos = _pos;
	rot = _rot;
	scale = _scale;
	size = _size;

	bounding = _bounding;
}

void Rigidbody::Update()
{
	vel.x *= friction;
	//vel.y += gravity;

	*pos += vel * Engine::GetDT();
	/*cout << lastRot << "::" << *rot << endl;
	cout << bounding.ToString() << endl;*/

	if (lastRot != *rot)
	{
		float d = *rot - lastRot;
		bounding.vLL = Math::RotatePoint(bounding.vLL, { 0 }, d);
		bounding.vLR = Math::RotatePoint(bounding.vLR, { 0 }, d);
		bounding.vUL = Math::RotatePoint(bounding.vUL, { 0 }, d);
		bounding.vUR = Math::RotatePoint(bounding.vUR, { 0 }, d);
		lastRot = *rot;
	}
}

void Rigidbody::Render(Vector3 c)
{
	glLoadIdentity();

	glTranslatef(pos->x, pos->y, pos->z);
	//glScalef(scale->x, scale->y, scale->z);

	glColor4f(c.x, c.y, c.z, 1);
	glLineWidth(6);
	glBegin(GL_LINES);
	{
		//float x, y;
		//x = size->x / 2;
		//y = size->y / 2;

		glVertex2f(bounding.vLL.x, bounding.vLL.y);
		glVertex2f(bounding.vLR.x, bounding.vLR.y);

		glVertex2f(bounding.vLR.x, bounding.vLR.y);
		glVertex2f(bounding.vUR.x, bounding.vUR.y);

		glVertex2f(bounding.vUR.x, bounding.vUR.y);
		glVertex2f(bounding.vUL.x, bounding.vUL.y);

		glVertex2f(bounding.vUL.x, bounding.vUL.y);
		glVertex2f(bounding.vLL.x, bounding.vLL.y);

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






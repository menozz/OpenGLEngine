#ifndef RIGIDBODY
#define RIGIDBODY
#include "../Math/Vector3.h"

class Rigidbody
{
	Vector3* pos;
	Vector3* scale;
	Vector3* size;
	float* rot;

	float gravity;
	float friction;
	Vector3 vel;

public:

	Rigidbody();

	void Initialize(float _friction, float _gravity, Vector3* _pos, float* rot, Vector3* _scale, Vector3* _size);
	
	void Update();
	void Render(Vector3 c);

	void AddForce(Vector3 f);
	void SetVel(Vector3 _vel);
};

#endif
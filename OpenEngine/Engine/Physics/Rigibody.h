#ifndef RIGIDBODY
#define RIGIDBODY
#include "../Math/Vector3.h"
#include "../Math/Rect.h"

class Rigidbody
{
	Vector3* pos;
	Vector3* scale;
	Vector3* size;
	
	float* rot;
	float lastRot;

	float gravity;
	float friction;
	Vector3 vel;

	Rect bounding;

public:

	static bool IsColliding(const Rigidbody& rbA, const Rigidbody& rbB);

	Rigidbody();

	void Initialize(float _friction, float _gravity, Vector3* _pos, float* rot, Vector3* _scale, Vector3* _size, Rect _bounding);
	
	void Update();
	void Render(Vector3 c);

	void AddForce(Vector3 f);
	
	Vector3 GetVel();
	void SetVel(Vector3 _vel);
};

#endif
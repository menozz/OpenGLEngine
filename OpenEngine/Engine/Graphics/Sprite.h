#ifndef SPRITE
#define SPRITE

#include "GLFW/glfw3.h"
#include  <iostream>
#include  "Texture.h"
#include "../Math/Vector3.h"

using namespace std;

class Sprite
{ 
	Texture texture;

	Vector3 pos;
	Vector3 scale;

	float rot;
	float speed;


public:

	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 pos);

	void Update();
	void Render();

	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void RotateTo(float x);
	void RotateBy(float x);

	void SetScale(float x);
	void SetScale(Vector3 v);

	void SpeedTo(float x);
	void SpeedBy(float x);
};

#endif

#ifndef SPRITE
#define SPRITE

#include "GLFW/glfw3.h"
#include  <iostream>
#include  "Texture.h"

using namespace std;

class Sprite
{
	Texture texture;
	float xPos;
	float yPos;
	float rot;
	float xScale, yScale;
	float speed;

public:

	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float xPos, float yPos);

	void Update();
	void Render();

	void MoveTo(float x, float y);
	void MoveBy(float x, float y);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void RotateTo(float x);
	void RotateBy(float x);

	void SetScale(float x);
	void SetScale(float x, float y);

	void SpeedTo(float x);
	void SpeedBy(float x);
};

#endif

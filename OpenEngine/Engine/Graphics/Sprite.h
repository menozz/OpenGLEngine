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


public:

	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float xPos, float yPos);

	void Update();
	void Render();

	void SetPos(float x, float y);
	void SetRot(float x);
	void SetScale(float x);
	void SetScale(float x, float y);
};

#endif

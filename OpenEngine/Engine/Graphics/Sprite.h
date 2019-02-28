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

public:

	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float xPos, float yPos);

	void Update();
	void Render();

	void SetPos(float x, float y);
};

#endif

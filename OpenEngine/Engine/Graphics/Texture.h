#ifndef TEXTURE
#define TEXTURE

#include "GLFW/glfw3.h"
#include "soil.h"

#include <iostream>
#include <string>
using namespace  std;

class Texture
{
	int id;
	int w;
	int h;

	bool GetTextureParams();

public:

	Texture();
	Texture(int id);
	Texture(string path);

	int GetID();
	int GetWidth();
	int GetHeight();
};
#endif


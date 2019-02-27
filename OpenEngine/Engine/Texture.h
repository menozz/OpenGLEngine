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
	int width;
	int height;

	bool LoadImage(const char* path, unsigned int flags);
public:

	Texture();
	Texture(int id);
	Texture(string path);

	int GetID();
	int GetWidth();
	int GetHeight();

};
#endif


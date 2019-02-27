#include "Texture.h"

Texture::Texture()
{
	id = -1;

}

Texture::Texture(int id)
{
	this->id = id;
}

Texture::Texture(string path)
{
	
}


int Texture::GetID()
{
	return id;
}

int Texture::GetHeight()
{
	return height;
}

int Texture::GetWidth()
{
	return width;
}



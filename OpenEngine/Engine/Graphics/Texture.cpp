#include "Texture.h"

Texture::Texture()
{
	id = -1;
}

Texture::Texture(int id)
{
	this->id = id;
	if (!GetTextureParams())
	{
		cout << "Error loading image with ID: " << id << endl;
	}
}

Texture::Texture(string path)
{
	id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA);
	if(!GetTextureParams())
	{
		cout << "Error loading image from FILE: " << path << endl;
	}
}

bool Texture::GetTextureParams()
{
	if (id > 0)
	{
		int mipLevel = 0;
		glBindTexture(GL_TEXTURE_2D, id);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &w);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &h);
		return true;
	}

	return false;
}

int Texture::GetID()
{
	return id;
}

int Texture::GetHeight()
{
	return h;
}

int Texture::GetWidth()
{
	return w;
}



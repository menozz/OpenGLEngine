#include "Rect.h"
#include <sstream>

string Rect::ToString()
{
	stringstream ss;
	ss << "Pos(" << pos.x << ", " << pos.y << ", " << pos.z << ")" - "Size (" << size.x << ", " << size.y << ", " << size.z << ")";
	ss << "LL.X: " << vLL.x << "\tY: " << vLL.y << endl;
	ss << "UL.X: " << vUL.x << "\tY: " << vUL.y << endl;
	return ss.str();
 }

Rect::Rect()
{
	pos = { 0 };
	size = { 0 };
	UpdateVertices();
}

Rect::Rect(Vector3 _size) : Rect()
{
	pos = { 0 };
	size = _size;
	UpdateVertices();
}

Rect::Rect(Vector3 _pos, Vector3 _size) : Rect(_size)
{
	pos = _pos;
	UpdateVertices();
}

void Rect::MoveBy(Vector3 by)
{
	pos += by;
	UpdateVertices();
}

void Rect::MoveTo(Vector3 to)
{
	pos = to;
	UpdateVertices();
}

void Rect::SetSize(Vector3 _size)
{
	size = _size;
	UpdateVertices();
}

void Rect::UpdateVertices()
{
	vLL = Vector3(pos.x - size.x / 2, pos.y - size.y / 2, 0);
	vLR = Vector3(pos.x + size.x / 2, pos.y - size.y / 2, 0);
	vUL = Vector3(pos.x - size.x / 2, pos.y + size.y / 2, 0);
	vUR = Vector3(pos.x + size.x / 2, pos.y + size.y / 2, 0);
}





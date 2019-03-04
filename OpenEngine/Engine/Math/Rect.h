#ifndef RECT
#define  RECT
#include "Vector3.h"
#include <string>
using namespace std;

class Rect
{
	Vector3 pos;
	Vector3 size;

	
public:

	Vector3 vUL;
	Vector3 vUR;
	Vector3 vLL;
	Vector3 vLR;

	string ToString();

	Rect();
	Rect(Vector3 _size);
	Rect(Vector3 _pos, Vector3 _size);

	void MoveBy(Vector3 by);
	void MoveTo(Vector3 to);

	void SetSize(Vector3 _size);
	void UpdateVertices();
};

#endif


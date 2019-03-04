#ifndef  MATH
#define MATH
#include "Vector3.h"
#include <vector>

#define PI 3.14159
using namespace  std;
namespace Math
{
	Vector3 RotatePoint(Vector3 point, Vector3 pivot, float rot);
	double ConvertToRadians(double degrees);
	double ConvertToDegrees(double radians);
	float Min(vector<float> x);
	float Max(vector<float> x);
}


#endif

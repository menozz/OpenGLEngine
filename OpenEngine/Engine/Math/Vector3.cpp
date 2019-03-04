#include "Vector3.h"
#include <cmath>

float Vector3::Dot(const Vector3& a, const Vector3& b)
{
	return a.x * b.x + a.y* b.y;
}

Vector3 Vector3::Project(const Vector3& a, const Vector3& b)
{
	return {
		(Dot(a, b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2))) * b.x,
		(Dot(a, b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2))) * b.y,
		0
	};
}

Vector3::Vector3() : Vector3(0)
{
}

Vector3::Vector3(float x)
{
	this->x = y = z = x;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::operator+(const Vector3& other) const
{
	return { x + other.x, y + other.y, z + other.z };
}

Vector3 Vector3::operator-(const Vector3& other) const
{
	return { x - other.x, y - other.y, z - other.z };
}

Vector3 Vector3::operator*(const Vector3& other) const
{
	return { x * other.x, y * other.y, z * other.z };
}

Vector3 Vector3::operator*(float _x) const
{
	return { this->x * _x, y * _x, z * _x };
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

Vector3& Vector3::operator-=(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;

	return *this;
}

bool Vector3::operator==(const Vector3& other) const
{
	return x == other.x && y == other.y && z == other.z;
}

bool Vector3::operator!=(const Vector3& other) const
{
	return !operator==(other);
}







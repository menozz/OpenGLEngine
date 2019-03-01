#ifndef  VECTOR
#define VECTOR

class Vector3
{
public:
	
	Vector3();
	//Vector3(const Vector3& other);
	Vector3(float x);
	Vector3(float x, float y, float z);

	//Vector3& operator=(const Vector3& other);
	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	Vector3 operator*(const Vector3& other) const;
	Vector3 operator*(float x) const;

	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);

	bool operator==(const Vector3& other) const;
	bool operator!=(const Vector3& other) const;

	float x, y, z;
};

#endif


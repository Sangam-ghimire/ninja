#ifndef __Vector2D__
#define __Vector2D__
#include<math.h>

class Vector2D {
private:
	float m_x;
	float m_y;

public:
	Vector2D(float x, float y) : m_x(x), m_y(y) {}// using intialization list

	float getX() { return m_x; }
	float getY() { return m_y; }

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	float length() { return sqrt(m_x * m_x + m_y * m_y); }

	//operator overloading
	Vector2D operator+(const Vector2D &v2) const
	{
		return Vector2D(m_x + v2.m_x, v2.m_y + v2.m_y);
	}
	//using friend function allows to pass two parameters while overloading.we have also used the above overloading inside it
	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}
	
	Vector2D operator*(float scalar) 
	{
		return Vector2D(m_x * scalar, m_y * scalar);
	}

	Vector2D& operator*=(float scalar)//study this is also a type of friend function
	{
		m_x *= scalar;
		m_y *= scalar;

		return *this;
	}

	Vector2D operator-(const Vector2D &v2) const
	{
		return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
	}

	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;

		return v1;
	}

	Vector2D operator/ (float scalar)
	{
		return Vector2D(m_x / scalar, m_y / scalar);
	}

	Vector2D& operator/= (float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;

		return *this;
	}

	void normalize() 
	{
		float l = length();
		if (1 > 0)//dividing by only greater than 0
		{
			(*this) *= 1 / 1;
		}
	}
};
typedef Vector2D TheVector;
#endif

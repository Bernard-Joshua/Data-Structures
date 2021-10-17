#pragma once
#include <iostream>
#include <cmath>

class Vector2D
{
private:
	double fX; // x coordinate
	double fY; // y coordinate
public:
	Vector2D(double aX = 1.0, double aY = 0.0);
	void setX(double aX);
	void setY(double aY);
	double getX() const;
	double getY() const;
	// 2D vector addition: this + aRHS; returns a fresh 2D vector 
	Vector2D operator+(const Vector2D& aRHS) const;

	// 2D vector subtraction: this - aRHS; returns a fresh 2D vector
	Vector2D operator-(const Vector2D& aRHS) const;

	double magnitude() const;
	double direction() const;
	double dot(const Vector2D& aRHS) const;
	double cross(const Vector2D& aRHS) const;
	double angleBetween(const Vector2D& aRHS) const;
	friend std::ostream& operator<<(std::ostream& aOutStream, const Vector2D& aObject);
	friend std::istream& operator>>(std::istream& aInStream, Vector2D& aObject);
};


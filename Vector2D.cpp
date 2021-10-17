#include "Vector2D.h"

// Constructor
Vector2D::Vector2D(double aX, double aY): fX(aX), fY(aY){ }

//Setters
void Vector2D::setX(double aX){ fX = aX;}
void Vector2D::setY(double aY) { fY = aY;}

//Getters
double Vector2D::getX() const { return fX; }
double Vector2D::getY() const { return fY; }

//2D Vector Addtion
Vector2D Vector2D::operator+(const Vector2D& aRHS) const
{
	return Vector2D(fX + aRHS.fX, fY + aRHS.fY); // Returns a fresh 2D vector
}

//2D Vector Subtraction
Vector2D Vector2D::operator-(const Vector2D& aRHS) const
{
	return Vector2D(fX - aRHS.fX, fY - aRHS.fY); // Returns a fresh 2D vector
}

// Magnitude of Vector:  The distance between the initial point  and the end point  
double Vector2D::magnitude() const
{
	return sqrt((fX * fX) + (fY * fY)); // Utilizes sqrt() function from cmath library to carry out square rooting.
}

// Direction of Vector: Describes the movement of vector either left or right 
double Vector2D::direction() const
{
	return atan2(fY,fX); // atan2() function returns the arc tangent of the two numbers x and y.
}

// Calculates the Scalar/Dot product of a Vectors.
double Vector2D::dot(const Vector2D& aRHS) const
{
	//Error handling
	if (fX && fY == 0 || aRHS.fX && aRHS.fY == 0)
		return 0;
	return fX * aRHS.fX + fY * aRHS.fY; // Returns dot product if not null value
}

//Calculates the Cross Product of Vectors
double Vector2D::cross(const Vector2D& aRHS) const
{
	return fX * aRHS.fY - fY * aRHS.fX;
}

// Calculates the Angle Between two Vectors
double Vector2D::angleBetween(const Vector2D& aRHS) const
{
	double dMag = (this->magnitude() * aRHS.magnitude()); // Dot exception handled in dot function already.

	// If denominator is zero return 0
	if (dMag == 0) 
		return 0;

	return acos(this->dot(aRHS) / dMag);	
}

//Friend Function for output
std::ostream& operator<<(std::ostream& aOutStream, const Vector2D& aObject)
{
	aOutStream << " ( " << aObject.fX << ", " << aObject.fY << " )\n";
	return aOutStream;
}

//Friend Function for input
std::istream& operator>>(std::istream& aInStream, Vector2D& aObject)
{
	aInStream >> aObject.fX;
	aInStream >> aObject.fY;
	return aInStream;
}

#include "Point2D.h"

static const Point2D gCoordinateOrigin; // Const global

// Constructors
Point2D::Point2D() : fId(" "), fPosition(0, 0), fOrigin(&gCoordinateOrigin) { }

Point2D::Point2D(const std::string& aId, double aX, double aY) : fId(aId), fPosition(aX, aY), fOrigin(&gCoordinateOrigin) { }

// Explicit Constructor
Point2D::Point2D(std::istream& aIStream) : fOrigin(&gCoordinateOrigin)
{
	aIStream >> fId >> fPosition;
}

//Getters 
const std::string& Point2D::getId() const { return fId; }
const double Point2D::getX() const { return fPosition.getX(); }
const double Point2D::getY() const { return fPosition.getY(); }
const Point2D& Point2D::getOrigin() const { return *fOrigin; }

//Setters
void Point2D::setX(const double& aX) { fPosition.setX(aX); }
void Point2D::setY(const double& aY) { fPosition.setY(aY); }
void Point2D::setOrigin(const Point2D& aPoint) { fOrigin = &aPoint; }

// 2D vector this – aRHS
Vector2D Point2D::operator-(const Point2D& aRHS) const
{
	return (fPosition - aRHS.fPosition);
}

//Provides accesiblity to private function directionTo()
double Point2D::direction() const
{
	return fOrigin->directionTo(*this);
}

//Provides accesiblity to private function directionTo()
double Point2D::magnitude() const
{
	return fOrigin->magnitudeTo(*this);;
}

//Checks to see if Points are collinear
bool Point2D::isCollinear(const Point2D& aOther) const
{
	if (fPosition.cross(aOther.fPosition) == 0)
	{
		return true;
	}

	return false;
}

// Checks to see if Points turn left or right
bool Point2D::isClockwise(const Point2D& aP0, const Point2D& aP2) const
{
	double val = (fPosition.cross(aP0.fPosition) - aP2.fPosition.cross(aP0.fPosition));

	if (val >= 0) // If more than 0 it turns right 
	{
		return true;
	}

	return false;
}

// Operator overloading to check comparator later on
bool Point2D::operator<(const Point2D& aRHS) const
{
	if (fPosition.getY() < aRHS.getY())
	{
		return true;
	}
	else if (fPosition.getY() == aRHS.getY()) {
		if (fPosition.getX() > aRHS.getX()) {
			return true;
		}
	}
	return false;
}


//Returns the direction from the target point to aOther,
double Point2D::directionTo(const Point2D& aOther) const
{
	return (aOther.fPosition - fPosition).direction();
}

//Returns the magnitude from the target point to aOther,
double Point2D::magnitudeTo(const Point2D& aOther) const
{
	return (aOther.fPosition - fPosition).magnitude();
}

// Friend function for output
std::ostream& operator<<(std::ostream& aOStream, const Point2D& aObject)
{
	aOStream << aObject.fId << " : " << aObject.fPosition;
	return aOStream;
}

// Friend function for input
std::istream& operator>>(std::istream& aIStream, Point2D& aObject)
{
	aIStream >> aObject.fId >> aObject.fPosition;
	return aIStream;
}

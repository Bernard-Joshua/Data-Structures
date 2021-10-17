#include "Point2DSet.h"

#include <fstream>
#include <stdexcept>
#include <algorithm>

// Vector(Stack-like) strucuture add function
void Point2DSet::add(const Point2D& aPoint)
{
	fPoints.push_back(aPoint);
}

// Vector(Stack-like strucuture add function
void Point2DSet::add(Point2D&& aPoint)
{
	fPoints.push_back(std::move(aPoint));
}

// Vector(Stack-like) strucuture 'pop' function
void Point2DSet::removeLast()
{
	fPoints.pop_back(); //Removes last element from stack/vector.
}

//Checks to see is the Point2D is truning left or right.
bool Point2DSet::doesNotTurnLeft(const Point2D& aPoint) const
{
	return fPoints[size() - 1].isClockwise(fPoints[size() - 2], aPoint);
}

// Comaparator function to order the Points by coordinates
bool orderByCoordinates(const Point2D& aLeft, const Point2D& aRight)
{
	return aLeft < aRight;
}

// Comaparator function to order the Points by coordinates
bool orderByPolarAngle(const Point2D& aLHS, const Point2D& aRHS)
{
	if (aLHS.isCollinear(aRHS))
	{
		return aLHS.magnitude() > aRHS.magnitude();
	}

	return aLHS.direction() < aRHS.direction();
}

//Reads input from file and fills the vector with it.
void Point2DSet::populate(const std::string& aFileName)
{
	std::ifstream INPUT(aFileName);// Explicit constructor from Point2D class

	std::string id;
	double x;
	double y;

	//Uses friend function from Point2D class
	while (INPUT >> id >> x >> y)
	{
		Point2D z(id, x, y);
		add(z);
	}

	INPUT.close();

}

void Point2DSet::buildConvexHull(Point2DSet& aConvexHull)
{
	aConvexHull.clear();// Clears the stack each time it called

	sort(orderByCoordinates);

	for (size_t i = 0; i < size(); i++) {
		fPoints[i].setOrigin(fPoints[0]); // Sets origin for all elements.
	}

	sort(orderByPolarAngle);
	if (size() < 3)
		throw std::domain_error("Error.3 elements needed for algorithm to work!");
	//Elements less than 3 always added into stack which means element '0' and/or '1' are always present in the stack initially.
	aConvexHull.add(fPoints[0]); // Origin 
	aConvexHull.add(fPoints[1]); // Next-To-Top
	// If 3rd element does not exist the domain_error is thrown
	aConvexHull.add(fPoints[2]);

	//Graham's Scan Implementation
	for (size_t i = 3; i < size(); i++)
	{
		//Collinear Handling.	
		if (fPoints[i - 1].isCollinear(fPoints[i]))
		{
			continue; //i++;
		}
		while (aConvexHull.size() >= 2 && aConvexHull.doesNotTurnLeft(fPoints[i])) // Stack should have atleast 2 or more elements for 
		{																		  // Algorithm to work.
			aConvexHull.removeLast();
		}
		aConvexHull.add(fPoints[i]);
	}

}

//Returns size of Vector/Stack
size_t Point2DSet::size() const
{
	return fPoints.size();
}

//Clears Stack
void Point2DSet::clear()
{
	fPoints.clear();
}

//Sorting Function ( Sorts Vector based on Comparator Function
void Point2DSet::sort(Comparator aComparator)
{
	std::stable_sort(fPoints.begin(), fPoints.end(), aComparator);
}

// Operator Overloading for index accessibility for Vector/Stack
const Point2D& Point2DSet::operator[](size_t aIndex) const
{
	return fPoints[aIndex];
}

// Iterator for start of Vector
Point2DSet::Iterator Point2DSet::begin() const
{
	return fPoints.begin();
}

// Iterator for start of Vector
Point2DSet::Iterator Point2DSet::end() const
{
	return fPoints.end();
}






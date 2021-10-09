#pragma once
#include <cstddef> // include for size_t (unsigned integral type)
#include <iostream> // include in order to use ostream an istream
#include <Windows.h>
#include "IntVector.h" // Very Important (This will resolve incomplete class type errors)

// forward declaration of container class
class IntVector;

class IntVectorIterator
{
private:
	const IntVector& fContainer; // References the IntVector class ( Made possible through the use of forward declarations)
	size_t fPosition; // Gets the first position of the array (index)
public:
	IntVectorIterator(const IntVector& aContainer, size_t aStart = 0); // Constructor
	const size_t operator*() const; // Deferencing Operator
	IntVectorIterator& operator++(); // Prefix Operator
	IntVectorIterator operator++(int); // Postfix Operator
	bool operator==(const IntVectorIterator& aRHS) const; // Equality Operator
	bool operator!=(const IntVectorIterator& aRHS) const; // Inequality Operator
	IntVectorIterator begin() const;
	IntVectorIterator end() const;

	// Friend Function to Output the Iterator Iteration
	friend std::ostream& operator <<(std::ostream& out, const IntVectorIterator& rhs);
};

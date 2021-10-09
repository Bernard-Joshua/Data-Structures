#pragma once
#include <cstddef> // Include for size_t (unsigned integral type)
#include <atomic> // Include for std::move function
#include <iostream> // Include for ostream and istream
#include <stdexcept> // For exception handling
#include <iomanip> //Output presentation
#include <Windows.h> //Output presentation
// Include basic sorter definition
#include "IntSorter.h"
#include "CocktailShakerSort.h" // For friend function
// Include iterator definition
#include "IntVectorIterator.h"

class IntVectorIterator;

class IntVector
{
private:
	int* fElements;
	size_t fNumberOfElements;

public:
	//IntVector(IntVector& other);
	// Constructor: copy argument array
	IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements);
	// Destructor: release memory
	~IntVector();
	// size getter
	size_t size() const;
	// swap two elements within the vector
	void swap(size_t aSourceIndex, size_t aTargetIndex);
	// sort receives a callable Sorter object
	void sort(const IntSorter& aSorter);
	// indexer
	const int operator[](size_t aIndex) const;
	// iterator auxiliary methods (required for C++11 for-range loop)
	IntVectorIterator begin() const;
	IntVectorIterator end() const;


	//Friend Function
	friend std::ostream& operator<<(std::ostream& out, const IntVector& rhs);
	friend std::istream& operator>>(std::istream& in, IntVector& rhs);
};

#include "IntVector.h"

//Parameterized Constructor
IntVector::IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
{
	if(aNumberOfElements < 0)
		throw std::bad_array_new_length();

	fNumberOfElements = aNumberOfElements;

	fElements = new int[fNumberOfElements];
	for (size_t i = 0; i < fNumberOfElements; i++)
	{
		fElements[i] = aArrayOfIntegers[i];
		if (fElements[i] == NULL) {
			throw std::out_of_range(" VectFatal[2] Mismatch of Array Size => IntVector.cpp: Line 12");
		}
	}

}

//Destructor
IntVector::~IntVector() { delete[] fElements; } //Memory Deallocation ( CleanUp! )

//Getter Function
size_t IntVector::size() const { return fNumberOfElements; } // Inline code increases performance.

void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex)
{
	//Error Handling: Ensures that the indexes are within the bounds
	if (aTargetIndex > size() - 1 || aTargetIndex < 0) // source will never be 10;
	{
		throw std::out_of_range(" VectorErrNo[1]: Out of bounds for target => IntVect.cpp:Line 26");
	}
	else if (aSourceIndex > size() - 1 || aSourceIndex < 0) // source will never be 10;
	{
		throw std::out_of_range(" VectorErrNo[2]: Out of bounds for source => IntVect.cpp:Line 30");
	}
	//Move function does not copy the values. It 'moves' them from the source to the target.This improves performance.
	size_t temp = std::move(fElements[aSourceIndex]);
	fElements[aSourceIndex] = std::move(fElements[aTargetIndex]);
	fElements[aTargetIndex] = std::move(temp);
}

// Sorter Function that is derived from IntSorter class.
void IntVector::sort(const IntSorter& aSorter) { return aSorter(*this); } // Inline code increases performance.


const int IntVector::operator[](size_t aIndex) const
{
	//Ensures that the index is within the range of 0 and the last element of the array
	if (aIndex > size()) {
		throw std::out_of_range(" VectorErrNo[3]: Index is out bounds => IntVector.cpp: Line 49"); // Throws an error message if index is out or range
	}

	return fElements[aIndex];
}

// Auxilary Method
IntVectorIterator IntVector::begin() const
{
	return IntVectorIterator(*this, 0); // Returns a fresh set of iterators to the "first" element
}

// Auxilary Method
IntVectorIterator IntVector::end() const
{
	return IntVectorIterator(*this, size()); // Returns a fresh set of iterators to the "past-the-end" element
}


// Friend Function For Output
std::ostream& operator<<(std::ostream& out, const IntVector& rhs)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	out << std::setw(55) << std::setfill('-') << '\n';
	out << " |" << std::setw(35) << std::setfill(' ') << "Indexer Method: " << std::setw(19) << " |\n";
	out << " " << std::setw(55) << std::setfill('-') << '\n';
	out << " | Before Sorting:" << std::setw(3) << std::setfill(' ') << "|";
	// By default uses Indexer method to iterate through elements unless it calls upon an Iterator to do so
	SetConsoleTextAttribute(h, 9);
	for (size_t i = 0; i < rhs.size(); i++)
	{
		out << " " << rhs[i];
	}
	SetConsoleTextAttribute(h, 6);
	out << "  |";
	out << "\n " << std::setw(55) << std::setfill('-');

	return out;
}


// Friend Function For Input (Sorting Algorithm)
std::istream& operator>>(std::istream& in, IntVector& rhs)
{
	// This is to enable the usage of the sorting algorithms.
	CocktailShakerSort c;
	rhs.sort(c);

	return in;
}





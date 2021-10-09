#include "IntVectorIterator.h"

// Constructor. "fContainer" must be initialized first before putting into constructor body (Stack Overflow).
IntVectorIterator::IntVectorIterator(const IntVector& aContainer, size_t aStart) : fContainer(aContainer)
{
	fPosition = aStart; //Initializes the fPosition to '0' as aStart = '0'. This points to the first position in the array.
}

//Derefercing Operator
const size_t IntVectorIterator::operator*() const
{
	return fContainer[fPosition];
}

// Postfix Increment
IntVectorIterator& IntVectorIterator::operator++()
{
	fPosition++; // Increments the index
	return *this; // Returns reference of the current Iterator set forward.
}

IntVectorIterator IntVectorIterator::operator++(int)
{
	IntVectorIterator It = *this;
	++(*this); // Increments the Iterator
	return It; // Returns a copy of the old Iterator.
}

bool IntVectorIterator::operator==(const IntVectorIterator& aRHS) const
{
	//Takes into context the index and the element when comparing two Iterators to see if their equal or not.
	return (fPosition == aRHS.fPosition) && (&fContainer == &aRHS.fContainer);

}

bool IntVectorIterator::operator!=(const IntVectorIterator& aRHS) const
{
	return !(*this == aRHS); // Same as using '!=' instead of '=='. Does the opposite of '=='
}

IntVectorIterator IntVectorIterator::begin() const
{
	return fContainer.begin(); // Auxilary Method
}

IntVectorIterator IntVectorIterator::end() const
{
	return fContainer.end(); // Auxilary Methods
}

std::ostream& operator<<(std::ostream& out, const IntVectorIterator& rhs)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	out << " |" << std::setw(35) << std::setfill(' ') << "Iterator Method:" << std::setw(19) << " |\n";
	out << " " << std::setw(55) << std::setfill('-') << '\n';
	out << " | After Sorting: " << std::setw(3) << std::setfill(' ') << " |";

	// C++ 11 and simpler method of iterating/looping called "range for statement"
	SetConsoleTextAttribute(h, 9);
	for (const auto& i : IntVectorIterator(rhs)) // Swinburne "Week 5: Iterators" pages 21-28
	{
		out << " " << i;
	}
	SetConsoleTextAttribute(h, 6);
	out << "  |";
	out << "\n " << std::setw(55) << std::setfill('-') << "\n";
	SetConsoleTextAttribute(h, 2);
	out << "\n VectorProcess: Success! => ";
	system("Pause");

	return out;
}

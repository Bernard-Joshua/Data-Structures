#include <iomanip> //Output presentation
#include <Windows.h> //Output presentation
#include "IntVector.h"
#include "IntVectorIterator.h"
#include "IntSorter.h"

using namespace std;

void runSorter(int[], size_t);
void testErrorExceptions(int[], int);
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{


	int arr[] = { 34,65,890,86,16,218,20,49,2,29 };
	size_t size = (sizeof(arr) / sizeof(arr[0]));// Gets exact arr size. (Makes the program more flexible as the more \
													elements can be added to the array and the size will auto update.

	// Catches exceptions
	try {

		// IntVector With Sorter (Problem 2). [ Test by changing size manually to more than 10 or less than 0]
		runSorter(arr, size);// If size is more than the arr elements or less than (negative value) error messages are generated.

		// Problem 1: For Testing ( Uncomment to test the exception Handling)
		//testErrorExceptions(arr, size);//*/

	}
	catch (std::out_of_range& e) { // Handles range exceptions.
		SetConsoleTextAttribute(h, 4);
		std::cout << e.what() << "\n";
		std::cout << "\n";
		std::cout << " VectorProcess: Failed! => ";
		system("Pause");
	}
	catch (std::bad_array_new_length o) { // Handles range exceptions.
		SetConsoleTextAttribute(h, 4);
		std::cout << " VectFatal[1] "<< o.what() << ": 'No-Negatives' = > IntVector.cpp: Line: 8\n";
		std::cout << " VectorProcess: Failed! => ";
		system("Pause");
	}
	SetConsoleTextAttribute(h, 7);
	return 0;

}

//Output and Output Presentation. (Question 2)
void runSorter(int arr[], size_t size)
{
	IntVector v(arr, size);
	IntVectorIterator VIt(v);
	SetConsoleTextAttribute(h, 6);
	cout << " **************** Cocktail Shaker Sort **************** \n";
	cout << '\n';
	cout << " " << v; // Outputs the vector/array (ostream)
	cout << "\n";
	cin >> v; // Gets the CockTailShakerSort algorithm (istream)
	cout << VIt; // The values of the swapped indexes will differ from the indexer method since the swap() function was called. (ostream: Iterator)
	cout << "\n";
}

// Exception handlers (Question 1)
void testErrorExceptions(int arr[], int size)
{
	IntVector z(arr, size);

	/* Uncomment To Test //*/
	
	//z.swap(-1, 7); // Will return error for source index out of range.
	//z.swap(11,8); // Will return error for source index out of range.
	//z.swap(1,-7); // Will return error for target index out of range.
	//z.swap(1,70); // Will return error for target index out of range.
	std::cout << z[-1];  // Test the exception handling for out of range.

	// If sucessfull then the following will be printed
	for (auto const& i : IntVectorIterator(z))
	{
		std::cout << " " << i;
	}
}




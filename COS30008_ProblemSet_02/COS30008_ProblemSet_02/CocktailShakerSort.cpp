#include "CocktailShakerSort.h"

void CocktailShakerSort::operator()(IntVector& aContainer) const
{
	int start = 0; // Start of array 
	int end = aContainer.size() - 1; // End of array 
	int val = 1; // For swtiching between left and right iteration

	while (end != 0 && start != aContainer.size())
	{
		switch (val)
		{
		case 1:
			for (int i = start; i < end; ++i)// Iterating From left to right
				if (aContainer[i] > aContainer[i + 1])
				{
					aContainer.swap(i, i + 1); // Calling on "IntVector Class" swap method
					val = 2; // After a successfull iteration from the left to right it will switch to right to left;
				}
			--end; // Since the last number is now the largets the size of the next iteration should be reduced.
			break;
		case 2:
			for (int i = end; i >= start; --i)
				if (aContainer[i] > aContainer[i + 1])
				{
					aContainer.swap(i, i + 1); // Calling on "IntVector Class" swap method.
					val = 1; // After a successfull iteration from the right to left it will switch to left to right;
				}
			++start; // Since the first number is now the smallest the starting index of the array it should be ignored 
		}
	}
}



/*
 * One of Swinburnes requirements is to not use 'flags' to check the algorithm (CockTailShakerSort). (PS2 Page 4)
 * Example of flags: booleans like 'isSwapped' or 'is-sorted' that check to see if a swap has occured etc...
 * The use of  "flags" increases the algorithms execution time by an average of 2 miliseconds. (25 milliseconds)
 * The current code reduces this and is more efficient. (23 milliseconds)
 * See the template "Time" on Canvas submissions to see how the time elapsed was calculated.
//*/



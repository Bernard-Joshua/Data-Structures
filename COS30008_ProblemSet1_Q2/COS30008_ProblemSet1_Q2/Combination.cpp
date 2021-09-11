#include "Combination.h"

Combination::Combination(unsigned int aN, unsigned int aK)
{
	fN = aN;
	fK = aK;
}

unsigned int Combination::getK() const { return fK; } // Making the getter functions inline improves performance.
unsigned int Combination::getN() const { return fN; } // Making the getter functions inline improves performance.

// Operator overloading.
unsigned long long Combination::operator()() const
{
	int coefficient = 1;

	// Validation
	if (fK > fN)  // When k > n, then the binominal coefficient is 0.
	{
		coefficient = 0;
	}
	if (fK <= fN) // When k <= n then only the calculation occurs.
	{
		// Counting Combinations. 
		// Used Dynamic Programming method instaed of recursion to improve efficiency.
		for (int i = 0; i < fK; ++i)
		{
			coefficient *= (fN - i);
			coefficient /= (i + 1);
		}
	}


	return coefficient;
}


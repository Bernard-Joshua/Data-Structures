#pragma once
#include <iostream>
#include "IntSorter.h"
#include "IntVector.h"


class IntVector; // Forward Declaration


class CocktailShakerSort : public IntSorter
{
public:
	void operator()(IntVector& aContainer) const override;
};

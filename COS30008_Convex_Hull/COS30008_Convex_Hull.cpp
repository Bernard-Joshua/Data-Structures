#include <iostream>
#include <cmath> 
#include <iomanip>
#include "Point2DSet.h"

using namespace std;

int main()
{
	try {

		Point2DSet lSet;
		lSet.populate("Pointers.txt");
		cout << " -----------------------" << endl;
		cout << " |      Points:        |" << endl;
		cout << " -----------------------" << endl;
		
		for (const Point2D& p : lSet)
		{
			cout << "   ";
			cout << p;
		}
		cout << " -----------------------" << endl;

		cout << endl;
		Point2DSet lConvexHull;
		lSet.buildConvexHull(lConvexHull);
		cout << " ----------------------" << endl;
		cout << " |    Convex hull:    |" << endl; size_t lSize = lConvexHull.size();
		cout << " ----------------------" << endl;
		for (size_t i = 0; i < lSize; i++)
		{
			cout << " | " << setw(6) << lConvexHull[i].getId() << " -> " << lConvexHull[(i + 1) % lSize].getId() << setw(8) << " | " << endl;
		}
		cout << " ----------------------" << endl;
	}
	catch (const domain_error& e)
	{
		cout << "Caught: " << e.what() << endl;
		cout << "Possible Causes: " << endl;
		cout << "\t1. Corrupted File\n\t2. Wrong coordinate input value (string instead of digit)\n\t3. File contains less than 3 elements." << endl;
		cout << "Type: " << typeid(e).name() << endl;
	}

}






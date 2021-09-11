#include "Sales.h"

Sales::Sales() {};

Sales::Sales( vector<string> two, vector<string> four)
{
	b = two;
	d = four;
}

// To prompt user to know which model their going to input.
void Sales::modelPrompt(int i)
{
	switch (i)
	{
	case 0:
		cout << "Enter RS Pro with GPS Unit Sold (Monthly)" << '\n';
		break;
	case 1:
		cout << "Enter Transcend Drive Pro Unit Sold (Monthly)" << '\n';
		break;
	case 2:
		cout << "Enter H203 1080P Unit Sold (Monthly)" << '\n';
		break;
	case 3:
		cout << "Enter Pioneer Unit Sold (Monthly)" << '\n';
		break;
	default:
		break;
	}
}

// To prompt user to know which branch their going to input.
void Sales::branchPrompt(int j)
{
	switch (j)
	{
	case 0:
		cout << "For SJ Branch: ";
		break;
	case 1:
		cout << "For PJ Branch: ";
		break;
	case 2:
		cout << "For KL Branch: ";
		break;
	default:
		break;
	}
}

// Calculates the total sales for the branch based on the unit price.
int Sales::branchCalculate(int arr[][3], int a[], int j)
{
	int temp = 0;

	for (int i = 0; i < 4; ++i)
	{
		temp += (arr[i][j] * a[i]);
	}

	return temp;
}

// Calculates the frequency of the models based on the total number of units sold.
int Sales::modelCalculate(int arr[][3], int i)
{
	int temp = 0;

	for (int j = 0; j < 3; ++j)
	{
		temp += (arr[i][j]);
	}

	return temp;
}

// Data validation.
int Sales::myInt()
{
	int i;
	while (!(cin >> i))
	{
		cout << "Error! \nPlease Enter Digit Only: ";
		cin.clear();
		cin.ignore(123, '\n');
	}

	return abs(i);// Usage of 'abs()' function to remove negative-value but keep the integer.
}

//Overloaded Operator that takes in parameters.
void Sales::operator()(vector<int> a, vector<int> c)
{

	map<int, string, greater<int>> Map; //'greater' used to sort the map into descending order

	for (int x = 0; x < a.size(); ++x)
	{
		Map[a[x]] = b[x];
	}

	map<int, string, greater<int>> Maps; //'greater' used to sort the map into descending order
	for (int x = 0; x < c.size(); ++x)
	{
		Maps[c[x]] = d[x];
	}

	// Maps the Branch to the correlating Gross Sales. 
	cout << setw(40) << setfill('-') << " Branches " << setw(35) << setfill('-') << '\n';
	for (auto& el : Map) {
		cout << " Total gross sales for Branch " << el.second << " is: RM " << el.first << '\n';
	}

	//Getting the largest value for branch
	auto ite = Map.cbegin(); //Returns a constant iterator pointing to the first element in the container. 
	cout << '\n';
	cout << setw(40) << setfill('-') << " Best Branch! " << setw(35) << setfill('-') << '\n';
	cout << " The highest sales figure is RM " << ite->first << " by Branch " << ite->second << '\n';

	auto it = Maps.cbegin(); //Returns a constant iterator pointing to the first element in the container. 
	cout << '\n';
	cout << setw(40) << setfill('-') << " Dashcam Model " << setw(35) << setfill('-') << '\n';
	cout << " The most popular dash cammodel is " << it->second << " with unit sold of " << it->first << " units\n" ;
}

#include <iostream>
#include <iomanip>
#include "Sales.h"
using namespace std;

int main()
{
	int sj, pj, kl, r, t, h, p;
	vector<string> branches = { "SJ", "PJ", "KL" };
	vector<string> models = { "RS Pro with GPS", "Transcend Drive Pro", "H203 1080P", "Pioneer" };
	int unitPrice[4] = { 730, 850, 150, 350 }; // price is fixed!
	int unitSold[4][3];
	vector<int> b, m;
	Sales s(branches,models); // Creating an instance.

	//Getting User-Input.
	for (int i = 0; i < 4; ++i)
	{
		s.modelPrompt(i);
		for (int j = 0; j < 3; ++j)
		{
			s.branchPrompt(j);
			unitSold[i][j] = s.myInt(); //Error checking.
		}
		cout << '\n';
	}

	// Calculations for branch.
	sj = s.branchCalculate(unitSold, unitPrice, 0);
	pj = s.branchCalculate(unitSold, unitPrice, 1);
	kl = s.branchCalculate(unitSold, unitPrice, 2);
	b = { sj, pj, kl };
	
	//Calculations for models.
	r = s.modelCalculate(unitSold, 0);
	t = s.modelCalculate(unitSold, 1);
	h = s.modelCalculate(unitSold, 2);
	p = s.modelCalculate(unitSold, 3);
	m = { r, t, h, p };
	
	system("CLS"); // Clears screen/terminal.

	//Overloaded Operator call that takes two parameters. Also outputs the results of the calculations.
	cout << setw(50) << setfill('=') << " Monthly Sales Figures " << setw(27) << setfill('=') << '\n';
	cout << '\n';
	s(b, m);
	cout << setw(75) << setfill('=') << '\n';

}


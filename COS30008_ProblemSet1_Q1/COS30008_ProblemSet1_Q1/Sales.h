#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

class Sales
{

private:
	vector<int> a;
	vector<string> b;
	vector<int> c;
	vector<string> d;
public:
	Sales();
	Sales(vector<string>, vector<string>);
	void modelPrompt(int);
	void branchPrompt(int);
	int branchCalculate(int arr[][3], int a[], int);
	int modelCalculate(int arr[][3], int);
	int myInt();
	void operator()(vector<int> , vector<int> );
};


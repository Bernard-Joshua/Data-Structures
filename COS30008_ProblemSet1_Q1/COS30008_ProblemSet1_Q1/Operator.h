#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Operator
{
public:
	vector<int> a;
	vector<string> b;
	vector<int> c;
	vector<string> d;
	Operator();
	Operator(vector<int>, vector<string>, vector<int>, vector<string>);
	void operator()();

};



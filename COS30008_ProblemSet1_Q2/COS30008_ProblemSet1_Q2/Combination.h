#include <iostream>
using namespace std;

class Combination
{
private:
	unsigned int fN;
	unsigned int fK;

public:
	Combination(unsigned int aN, unsigned int  aK);
	unsigned int getN() const;
	unsigned int getK() const;
	unsigned long long operator()() const;
};


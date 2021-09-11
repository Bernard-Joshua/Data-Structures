#include "COS30008_ProblemSet1_Q2.h"

int main()
{
    runProblem2();
}

void runProblem2()
{
    Combination a(6, 2);
    Combination b(5, 2);
    Combination c(28, 14);
    Combination d(52, 5);
    Combination e(5, 5);
    Combination f(10, 20); // Just to test that the validation is working. It should return 0.

    //Output
    cout << " ======= Combinations ======= " << endl;
    cout << setw(2) << a.getN() << setw(7) << " over " << setw(1) << a.getK() << setw(4) << " = " << a() << endl;
    cout << setw(2) << b.getN() << setw(7) << " over " << setw(1) << b.getK() << setw(4) << " = " << b() << endl;
    cout << setw(3) << c.getN() << setw(2) << " over " << setw(2) << c.getK() << setw(3) << " = " << c() << endl;
    cout << setw(3) << d.getN() << setw(2) << " over " << setw(1) << d.getK() << setw(4) << " = " << d() << endl;
    cout << setw(2) << e.getN() << setw(7) << " over " << setw(1) << e.getK() << setw(4) << " = " << e() << endl;
    cout << setw(3) << f.getN() << setw(5) << " over " << setw(1) << f.getK() << setw(3) << " = " << f() << endl;
    cout << " ============================ " << endl;
};
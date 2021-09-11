#include "Operator.h"

Operator::Operator() {};

Operator::Operator(vector<int> one, vector<string> two, vector<int> three, vector<string> four)
{
    a = one;
    b = two;
    c = three;
    d = four;
}

void Operator::operator()()
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
    for (auto& el : Map) {
        cout << " Total gross sales for Branch " << el.second << " is: RM " << el.first << endl;
    }


    //Getting the largest value for branch
    auto ite = Map.cbegin(); //Returns a constant iterator pointing to the first element in the container. 
    cout << endl;
    cout << " The highest sales figure is RM " << ite->first << " by Branch " << ite->second << endl;

    auto it = Maps.cbegin(); //Returns a constant iterator pointing to the first element in the container. 
    cout << endl;
    cout << " The most popular dash cammodel is " << it->first << " with unit sold of " << it->second << " units " << endl;
}
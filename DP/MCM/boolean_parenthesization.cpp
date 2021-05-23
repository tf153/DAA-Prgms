// T | F & T ^ F
//how many ways to put () to make the expression to be true

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int ways(string &exp, int i, int j, bool cond)
{
}

int main()
{
    string exp;
    cin >> exp;
    cout << ways(exp, 0, exp.length() - 1, true);
    return 0;
}
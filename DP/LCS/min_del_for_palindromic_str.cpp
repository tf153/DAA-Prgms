#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int min_del(string &s1, int n)
{
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int t[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 0;
        t[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    return n - t[n][n];
}

int main()
{
    string s;
    getline(cin, s);
    int n = s.length();
    cout << min_del(s, n);
    return 0;
}
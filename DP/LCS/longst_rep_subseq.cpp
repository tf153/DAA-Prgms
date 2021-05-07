#include <iostream>
#include <algorithm>
using namespace std;

string min_del(string &s1, int n)
{
    string ans = "", s2 = s1;
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
            if (s1[i - 1] == s2[j - 1] && i != j)
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    int i = n, j = n;
    while (i > 0 && j > 0)
    {
        if (t[i][j] == t[i - 1][j - 1] + 1)
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if (t[i][j] == t[i - 1][j])
            i--;
        else
            j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s;
    getline(cin, s); //AABEBCDD
    int n = s.length();
    cout << min_del(s, n); //ABD
    return 0;
}
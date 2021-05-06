#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string supersequence(string &str1, string &str2, int n, int m)
{
    int t[n + 1][m + 1];
    string ans = "";
    for (int i = 0; i <= n; i++)
        t[i][0] = 0;
    for (int i = 0; i <= m; i++)
        t[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (t[i][j - 1] > t[i - 1][j])
            {
                ans.push_back(str2[j - 1]);
                j--;
            }
            else
            {
                ans.push_back(str1[i - 1]);
                i--;
            }
        }
    }
    while (i > 0)
        ans.push_back(str1[--i]);
    while (j > 0)
        ans.push_back(str2[--j]);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int n = str1.length(), m = str2.length();
    cout << supersequence(str1, str2, n, m);
    return 0;
}

/*
a: "geek"
b: "eke"

ans: "geeke" = 5

//contains both strings subsequnces.

a: "aggtab"
b: "gxtxayb"

ans:"aggxtxayb" =9

NOTE  finding the longest common subsequnce
*/
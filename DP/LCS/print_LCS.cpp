#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string &str1, string &str2, int n, int m)
{
    int t[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        t[i][0] = 0;
    for (int i = 0; i <= m; i++)
        t[0][i] = 0;
    string ans = "";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1;
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    cout << t[n][m] << endl;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans.push_back(str1[i - 1]);
            j--;
            i--;
        }
        else
        {
            if (t[i][j - 1] > t[i][j - 1])
                j--;
            else
                i--;
        }
    }
    if (str1[0] == str2[0])
        ans.push_back(str1[0]);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int n = str1.length(), m = str2.length();
    cout << LCS(str1, str2, n, m);
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int LCSS(string &str1, string &str2, int n, int m)
{
    int t[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        t[i][0] = 0;
    for (int i = 0; i <= m; i++)
        t[0][i] = 0;
    int maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1;
            else
                t[i][j] = 0;
            if (maxx < t[i][j])
                maxx = t[i][j];
        }
    }
    return maxx;
}

int main()
{
    ios::sync_with_stdio(false);
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int n = str1.length(), m = str2.length();
    cout << LCSS(str1, str2, n, m);
    return 0;
}
//Minimum number of insertion and deletion to convert string A to B
#include <iostream>
#include <string>
using namespace std;

int min_ins_del(string &str1, string &str2, int n, int m)
{
    int t[n + 1][m + 1];
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
    int common = t[n][m];
    return n + m - 2 * common;
}

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int n = str1.length(), m = str2.length();
    cout << min_ins_del(str1, str2, n, m);
    return 0;
}
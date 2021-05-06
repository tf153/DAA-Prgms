#include <iostream>
#include <string>
#include <climits>
#include <cstring>
typedef long long int ll;
using namespace std;

int t[10][10];

int LCS(string &str1, string &str2, int n, int m)
{
    if (t[n][m] != -1)
        return t[n][m];
    if (n == 0 || m == 0)
        return 0;
    if (str1[n - 1] == str2[m - 1])
        return 1 + LCS(str1, str2, n - 1, m - 1);
    else
        return max(LCS(str1, str2, n - 1, m), LCS(str1, str2, n, m - 1));
}
int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int n = str1.length(), m = str2.length();
    memset(t, -1, sizeof(t));
    cout << LCS(str1, str2, n, m);
    return 0;
}
#include <iostream>
using namespace std;
bool match(string &str1, string &str2)
{
    int n = str1.length(), m = str2.length();
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
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }
    if (t[n][m] == n)
        return true;
    return false;
}
int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    cout << (match(str1, str2) ? "Yes" : "No");
    return 0;
}
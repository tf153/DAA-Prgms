#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

static int t[10000][10000];

bool isPalindrome(string s, int n)
{
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}

int min_partition(string &s, int i, int j)
{
    if (i >= j)
        return 0;
    if (t[i][j] != -1)
        return t[i][j];
    if (isPalindrome(s.substr(i, j - i + 1), j - i + 1))
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = 1 + min_partition(s, i, k) + min_partition(s, k + 1, j);
        ans = ans > temp ? temp : ans;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    memset(t, -1, sizeof(t));
    cout << min_partition(s, 0, s.length() - 1);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    long long dp[len];
    dp[0] = str[0] - '0';
    long long ans = dp[0];
    for (int i = 1; i < len; i++)
    {
        dp[i] = dp[i - 1] * 10 + (i + 1) * (str[i] - '0');
        dp[i] %= 1000000007;
        ans += dp[i];
        ans %= 1000000007;
    }
    cout << ans;
    return 0;
}
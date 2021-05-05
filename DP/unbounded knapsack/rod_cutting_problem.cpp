#include <iostream>
#include <climits>

#define rep(i, a, b) for (int i = a; i < b; i++)
#define fast \
    ios::sync_with_stdio(false)
using namespace std;
int t[10][10];
int max_profit(int price[], int len[], int max_len, int n)
{
    if (n == 0 || max_len == 0)
        return 0;
    if (len[n - 1] <= max_len)
        t[n][max_len] = max(price[n - 1] + max_profit(price, len, max_len - len[n - 1], n), max_profit(price, len, max_len, n - 1));
    else
        t[n][max_len] = max_profit(price, len, max_len, n - 1);
    return t[n][max_len];
}
int main()
{
    fast;
    int n;
    cin >> n;
    int price[n], len[n];
    rep(i, 0, n) cin >> len[i];
    rep(i, 0, n) cin >> price[i];
    cout << max_profit(price, len, n, n);
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
#define fast \
    ios::sync_with_stdio(false)
#define rep(i, a, b) for (int i = a; i < b; i++)
int t[10][10];
int coin_change(int coin[], int sum, int n)
{
    if (t[n][sum] != -1)
        return t[n][sum];
    if (n == 0 || sum == 0)
        return 0;
    if (coin[n - 1] <= sum)
        t[n][sum] = coin_change(coin, sum - coin[n - 1], n) + coin_change(coin, sum, n - 1);
    else
        t[n][sum] = coin_change(coin, sum, n - 1);
    return t[n][sum];
}
int main()
{
    fast;
    int n;
    cin >> n;
    int coin[n];
    rep(i, 0, n) cin >> coin[i];
    int sum;
    cin >> sum;
    memset(t, -1, sizeof(t));
    rep(i, 0, n + 1) t[i][0] = 1;
    rep(i, 1, sum + 1) t[0][i] = 0;
    cout << coin_change(coin, sum, n);
    return 0;
}
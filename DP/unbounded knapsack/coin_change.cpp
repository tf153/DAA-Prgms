#include <iostream>
using namespace std;
#define fast \
    ios::sync_with_stdio(false)
#define rep(i, a, b) for (int i = a; i < b; i++)
int coin_change(int coin[], int sum, int n)
{
    int t[n + 1][sum + 1];
    rep(i, 0, n + 1) t[i][0] = 1;
    rep(i, 1, sum + 1) t[0][i] = 0;
    rep(i, 1, n + 1)
        rep(j, 1, sum + 1)
    {
        if (coin[i - 1] <= j)
            t[i][j] = t[i][j - coin[i - 1]] + t[i - 1][j];
        else
            t[i][j] = t[i - 1][j];
    }
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
    cout << coin_change(coin, sum, n);
    return 0;
}
#include <iostream>
#include <numeric>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fast \
    ios::sync_with_stdio(false)
using namespace std;

int subset_diff(int arr[], int sum, int n)
{
    int t[n + 1][sum + 1];
    rep(i, 0, n + 1) t[i][0] = true;
    rep(i, 1, sum + 1) t[0][i] = false;
    rep(i, 1, n + 1)
    {
        rep(j, 1, sum + 1)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    fast;
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n) cin >> arr[i];
    int diff;
    cin >> diff;
    int sum = accumulate(arr, arr + n, 0);
    int sum1 = (diff + sum) >> 1;
    cout << subset_diff(arr, sum1, n);
    return 0;
}
#include <iostream>
#include <numeric>
#define fast \
    ios::sync_with_stdio(false)
using namespace std;
int min_diff(int arr[], int n)
{
    int sum, temp;
    temp = sum = accumulate(arr, arr + n, 0);
    sum >>= 1;
    bool t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        t[i][0] = true;
    for (int i = 1; i <= sum; i++)
        t[0][i] = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    for (int i = sum; i > 0; i--)
    {
        if (t[n][i])
        {
            return temp - 2 * i;
        }
    }
    return temp;
}
int main()
{
    fast;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << min_diff(arr, n);
    return 0;
}
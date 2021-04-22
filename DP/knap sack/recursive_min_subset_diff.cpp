#include <iostream>
#include <cstring>
#include <numeric>
#define fast \
    ios::sync_with_stdio(false)
using namespace std;
bool t[100][100];

bool min_subset(int arr[], int sum, int n)
{
    if (t[n][sum])
        return t[n][sum];
    if (n == 0 || sum == 0)
        return false;
    if (arr[n - 1] <= sum)
        return t[n][sum] = min_subset(arr, sum - arr[n - 1], n - 1) || min_subset(arr, sum, n - 1);
    return min_subset(arr, sum, n - 1);
}

int main()
{
    fast;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = accumulate(arr, arr + n, 0);
    memset(t, false, sizeof(t));
    for (int i = 0; i <= n; i++)
        t[i][0] = true;
    min_subset(arr, sum >> 1, n);
    for (int i = sum >> 1; i > 0; i--)
    {
        if (t[n][i])
        {
            cout << sum - 2 * i;
        }
    }
    return 0;
}
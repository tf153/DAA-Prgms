#include <iostream>
#include <cstring>
using namespace std;
int t[100][100];

int count_subset(int arr[], int sum, int n)
{
    if (t[n][sum] != -1)
        return t[n][sum];
    if (n == 0 || sum == 0)
        return 0;
    if (arr[n - 1] <= sum)
        return t[n][sum] = count_subset(arr, sum - arr[n - 1], n - 1) + count_subset(arr, sum, n - 1);

    return t[n][sum] = count_subset(arr, sum, n - 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;

    memset(t, -1, sizeof(t));
    for (int i = 0; i <= n; i++)
        t[i][0] = 1;
    for (int i = 1; i <= sum; i++)
        t[0][i] = 0;

    cout << count_subset(arr, sum, n);
    return 0;
}
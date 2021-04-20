#include <iostream>
using namespace std;
int count_subset(int arr[], int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        t[i][0] = 1;
    for (int i = 1; i <= sum; i++)
        t[0][i] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    return t[n][sum];
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
    cout << count_subset(arr, sum, n);
    return 0;
}
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int t[INT_MAX >> 17][INT_MAX >> 17];

int min_cost(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    if (t[i][j] != -1)
        return t[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = min_cost(arr, i, k) + min_cost(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        ans = ans > temp ? temp : ans;
    }
    return t[i][j] = ans;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(t, -1, sizeof(t));
    cout << sizeof(t) << endl;
    cout << min_cost(arr, 1, n - 1);
    return 0;
}
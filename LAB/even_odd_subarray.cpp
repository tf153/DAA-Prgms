#include <iostream>
using namespace std;
int even_odd_subarray(int arr[], int n)
{
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << even_odd_subarray(arr, n);
    return 0;
}
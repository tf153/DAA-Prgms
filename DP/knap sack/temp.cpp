#include <iostream>
#include <climits>
using namespace std;
int minJumps(int arr[], int n)
{
    int count[n];
    count[0] = 0;
    for (int i = 1; i < n; i++)
    {
        count[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && count[j] != INT_MAX)
            {
                count[i] = min(count[i], count[j] + 1);
                break;
            }
        }
    }
    return count[n - 1];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minJumps(arr, n + 1);
    return 0;
}

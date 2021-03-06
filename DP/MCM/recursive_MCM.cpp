//arr={40 20 30 10 30}
//matrix={(40*20),(20*30),(30,10),(10*30)}
//min_cost=26000
//as min cost => if (a* b) & (b*c) matrix cost of multiplication= a*b*c
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int min_cost(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = min_cost(arr, i, k) + min_cost(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        mn = mn > temp ? temp : mn;
    }
    return mn;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << min_cost(arr, 1, n - 1);
    return 0;
}
#include <iostream>
#include <climits>

using namespace std;

int min_coin(int arr[], int n, int sum)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i <= sum; i++)
        t[0][i] = INT_MAX - 1; //first row
    for (int i = 1; i <= n; i++)
        t[i][0] = 0; //first column

    for (int j = 1; j <= sum; j++)
    { //second row
        if (j % arr[0] == 0)
        {
            t[1][j] = j / arr[0];
        }
        else
            t[1][j] = INT_MAX - 1;
    }

    //dp
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = min(1 + t[i][j - arr[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
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
    cout << min_coin(arr, n, sum);
    return 0;
}
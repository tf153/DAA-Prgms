#include <iostream>
using namespace std;
bool subset_sum(int arr[], int sum, int n)
{
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
            {
                t[i][j] = t[i][j - arr[i - 1]] || t[i - 1][j];
            }
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
    if (subset_sum(arr, sum, n))
        cout << "Subset is possible";
    else
        cout << "Subset not possible";
    return 0;
}
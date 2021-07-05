#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, r, count = 0;
        cin >> n >> r;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] + sum < r)
            {
                count++;
                sum += arr[i];
            }
            else
            {
                break;
            }
        }
        cout << count << endl;
    }
    return 0;
}
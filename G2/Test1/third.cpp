#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        bool flag = false;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int leftsum[n], rightsum[n];
        leftsum[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            leftsum[i] = leftsum[i - 1] + arr[i];
        }
        rightsum[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightsum[i] = rightsum[i + 1] + arr[i];
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (leftsum[i] == rightsum[i])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
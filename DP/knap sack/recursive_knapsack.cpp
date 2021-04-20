//Given weight and value array of items, find the maximum value inside a knapsack of given weight.
#include <bits/stdc++.h>
using namespace std;
int max_val(int wt[], int val[], int w, int n)
{
    if (w == 0 || n == 0)
        return 0;
    if (wt[n - 1] <= w)
        return max(val[n - 1] + max_val(wt, val, w - wt[n - 1], n - 1), max_val(wt, val, w, n - 1));
    return max_val(wt, val, w, n - 1);
}
int main()
{
    int n;
    cin >> n;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int w;
    cin >> w;
    cout << max_val(wt, val, w, n);
    return 0;
}
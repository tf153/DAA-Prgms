#include <iostream>
#include <cstring>
using namespace std;
int t[100][100];
int max_value(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;
    if (t[n][w] != -1)
        return t[n][w];
    if (wt[n - 1] <= w)
        return t[n][w] = max(val[n - 1] + max_value(wt, val, w - wt[n - 1], n - 1), max_value(wt, val, w, n - 1));
    return t[n][w] = max_value(wt, val, w, n - 1);
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
    memset(t, -1, sizeof(t));
    cout << max_value(wt, val, w, n);
    return 0;
}
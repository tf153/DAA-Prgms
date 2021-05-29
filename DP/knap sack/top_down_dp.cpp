#include <iostream>
using namespace std;
int max_val(int wt[], int val[], int w, int n)
{
    int t[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
        t[i][0] = 0;
    for (int i = 0; i <= w; i++)
        t[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
            cout << t[i][j] << "\t";
        }
        cout << endl;
    }

    return t[n][w];
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
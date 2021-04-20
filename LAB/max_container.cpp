#include <iostream>
using namespace std;
int Max(int A[], int len)
{
    int l = 0;
    int r = len - 1;
    int area = 0;

    while (l < r)
    {
        area = max(area, min(A[l], A[r]) * (r - l));
        if (A[l] < A[r])
            l += 1;

        else
            r -= 1;
    }
    return area;
}
int main()
{
    ios::sync_with_stdio(false);
    int len;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    cout << Max(arr, len);
}
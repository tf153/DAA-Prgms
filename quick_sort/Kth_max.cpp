#include <iostream>
#include <stdlib.h>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int partition(int arr[], int l, int r)
{
    int random = rand() % (l + (r - l) / 2);
    swap(arr[random], arr[r]);
    int pivot = arr[r];
    int i = l - 1, j = l;
    while (j < r)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    return i + 1;
}
int Kth_max(int arr[], int l, int r, int &k)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        if (p == k)
            return arr[p];
        if (p < k)
            return Kth_max(arr, p, r, k);
        else
            return Kth_max(arr, l, p - 1, k);
    }
    return -1;
}
int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    k = n - k;
    cout << Kth_max(arr, 0, n - 1, k);
    return 0;
}
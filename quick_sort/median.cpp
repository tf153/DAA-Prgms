//Median of a number using quick_sort
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
    int random = rand() % (l + (r - l + 1) / 2);
    swap(arr[r], arr[random]);
    int pivot = arr[r];
    int i = l - 1, j = l;
    while (j < r)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    return i + 1;
}
int median(int arr[], int l, int r, int &m)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        if (m == p)
            return (arr[m]);
        else
        {
            if (p < m)
                return median(arr, p + 1, r, m);
            else
                return median(arr, l, p - 1, m);
        }
    }
    else
        return arr[l];
}
int main()
{
    int n, m;
    cin >> n;
    m = n / 2;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n & 1)
    {
        cout << median(arr, 0, n - 1, m);
    }
    else
    {
        cout << (median(arr, 0, n - 1, m) + median(arr, 0, n - 1, ++m)) / 2.0;
    }
    return 0;
}
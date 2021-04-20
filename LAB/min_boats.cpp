#include <iostream>
using namespace std;
void swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}
int *partition(int *first, int *last)
{
    int pivot = *(last);
    int *i = first - 1, *j = first;
    while (j < last)
    {
        if (*j < pivot)
        {
            i++;
            swap(i, j);
        }
        j++;
    }
    swap(i + 1, last);
    return i + 1;
}
void sort(int *first, int *last)
{
    if (last - first > 0)
    {
        int *p = partition(first, last);
        sort(first, p - 1);
        sort(p + 1, last);
    }
    else
        return;
}
int main()
{
    ios::sync_with_stdio(false);
    int len, count = 0;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    int limit;
    cin >> limit;
    sort(arr, arr + len - 1);
    int l = 0, r = len - 1;
    while (l <= r)
    {
        if (arr[r] + arr[l] <= limit)
        {
            count++;
            r--;
            l++;
        }
        else
        {
            count++;
            r--;
        }
    }
    cout << count;
    return 0;
}
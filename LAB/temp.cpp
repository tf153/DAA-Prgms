#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << *arr;
    cout << endl
         << *(arr + 5);
    return 0;
}
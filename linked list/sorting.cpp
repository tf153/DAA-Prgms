#include "struct.h"
#include "print.h"
#include "insert.h"
#include "sort.h"
using namespace std;
int main()
{
    int n, temp;
    node *head = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        insert(&head, temp);
    }
    print(head);
    cout << endl;
    sort(&head, 0, n - 1);
    print(head);
    return 0;
}

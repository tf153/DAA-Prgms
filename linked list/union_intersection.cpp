#include "struct.h"
#include "print.h"
#include "insert.h"
#include "sort.h"
using namespace std;
int main()
{
    int n1, n2, temp;
    cin >> n1 >> n2;
    node *head1 = nullptr;
    node *head2 = nullptr;
    for (int i = 0; i < n1; i++)
    {
        cin >> temp;
        insert(&head1, temp);
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> temp;
        insert(&head2, temp);
    }
    print(head1);
    cout << endl;
    print(head2);
    cout << endl;
    node *U = nullptr, *I = nullptr;
    Union(&U, head1, head2);
    Intersection(&I, head1, head2);
    print(U);
    cout << endl;
    print(I);
}
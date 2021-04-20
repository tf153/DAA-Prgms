#include "print.h"
#include "insert.h"
#include "struct.h"
using namespace std;
void add(node *head1, node *head2, bool &b)
{
    if (head1->next == nullptr)
    {
        head1->data += head2->data;
        if (head1->data > 9)
        {
            b = true;
        }
        return;
    }
    add(head1->next, head2->next, b);
    int t = b ? 1 : 0;
    head1->data += head2->data + t;
    b = head1->data > 9 ? true : false;
    return;
}
int main()
{
    int n1, n2, temp;
    bool b = false;
    node *head1 = nullptr, *head2 = nullptr;
    cin >> n1 >> n2;
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
    node *shift, *flag;
    if (n1 > n2)
    {
        shift = head1;
        for (int i = 0; i < n1 - n2; i++)
            shift = shift->next;
        add(shift, head2, b);
        shift = head1;
    }
    else
    {
        shift = head2;
        for (int i = 0; i < n2 - n1; i++)
            shift = shift->next;
        add(shift, head1, b);
        shift = head2;
    }
    if (b)
    {
        node *flg = new node();
        flg->data = shift->data % 10;
        flg->next = shift->next;
        shift->next = flg;
        shift->data /= 10;
    }
    while (shift != nullptr)
    {
        if (shift->data > 9)
            shift->data -= 10;
        shift = shift->next;
    }
    cout << endl;
    print((n1 > n2) ? head1 : head2);
    return 0;
}
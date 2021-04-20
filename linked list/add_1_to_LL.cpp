#include "struct.h"
#include "insert.h"
#include "print.h" //this contains iostream as well
using namespace std;
void add_1(node *head, bool &b)
{
    if (head->next == nullptr)
    {
        head->data += 1;
        if (head->data > 9)
        {
            b = true;
        }
        return;
    }
    add_1(head->next, b);
    int t = b ? 1 : 0;
    head->data += t;
    b = (head->data > 9) ? true : false;
    return;
}
int main()
{
    node *head = nullptr;
    int n, temp;
    bool b = false;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        insert(&head, temp);
    }
    print(head);
    add_1(head, b);
    node *move = head->next;
    while (move != nullptr)
    {
        if (move->data > 9)
            move->data -= 10;
        move = move->next;
    }
    if (head->data > 9)
    {
        head->data -= 10;
        node *temp = new node();
        temp->data = 1;
        temp->next = head;
        head = temp;
    }
    cout << endl;
    print(head);
    return 0;
}
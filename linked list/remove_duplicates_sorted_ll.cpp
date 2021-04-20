#include <iostream>
#include "struct.h"
#include "insert.h"
#include "print.h"
using namespace std;

void remove_duplicates(node *head)
{
    while (head->next != nullptr)
    {
        if (head->data == head->next->data)
        {
            node *temp = head->next;
            head->next = head->next->next;
            delete (temp);
        }
        else
        {
            head = head->next;
        }
    }
}

int main()
{
    int n, temp;
    node *head = nullptr;
    cin >> n;
    while (n--)
    {
        cin >> temp;
        insert(&head, temp);
    }
    print(head);
    remove_duplicates(head);
    cout << endl;
    print(head);
    return 0;
}
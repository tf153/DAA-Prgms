#include "merge.h"
void merge(node **head1, node *head2)
{
    node *temp = *head1, *ans = nullptr;
    if (temp->data > head2->data)
    {
        ans = head2;
        head2 = head2->next;
        ans->next = nullptr;
    }
    else
    {
        ans = temp;
        temp = temp->next;
        ans->next = nullptr;
    }
    *head1 = ans;
    while (temp != nullptr && head2 != nullptr)
    {
        if (temp->data > head2->data)
        {
            ans->next = head2;
            head2 = head2->next;
            ans = ans->next;
            ans->next = nullptr;
        }
        else
        {
            ans->next = temp;
            temp = temp->next;
            ans = ans->next;
            ans->next = nullptr;
        }
    }
    if (temp != nullptr)
    {
        ans->next = temp;
    }
    if (head2 != nullptr)
    {
        ans->next = temp;
    }
    return;
}
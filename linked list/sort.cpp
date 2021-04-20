#include "sort.h"
#include "print.h"
#include "merge.h"
void sort(node **head, int l, int r)
{
    if (l < r)
    {
        if (head == nullptr)
            return;
        int m = l + (r - l) / 2;
        node *temp = *head, *temp2;
        for (int i = l; i < m; i++)
            temp = temp->next;
        temp2 = temp;
        temp = temp->next;
        temp2->next = nullptr;
        sort(head, l, m);
        sort(&temp, m + 1, r);
        merge(head, temp);
    }
    return;
}
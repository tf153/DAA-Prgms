#include "insert.h"
void insert(node **head, int data)
{
    node *temp = new node();
    temp->data = data;
    temp->next = nullptr;
    if (*head == nullptr)
    {
        *head = temp;
    }
    else
    {
        node *move = *head;
        while (move->next != nullptr)
        {
            move = move->next;
        }
        move->next = temp;
    }
}

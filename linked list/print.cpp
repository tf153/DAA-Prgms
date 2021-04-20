#include "print.h"
void print(node *head)
{
    std::cout << head->data;
    head = head->next;
    while (head != nullptr)
    {
        std::cout << "->" << head->data;
        head = head->next;
    }
}
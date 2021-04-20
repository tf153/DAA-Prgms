#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void insert(node **head, int data)
{
    node *temp = new node();
    temp->data = data;
    temp->next = nullptr;
    if (*head == nullptr)
        *head = temp;
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
void print(node *head)
{
    if (head != nullptr)
    {
        cout << head->data;
        head = head->next;
        while (head != nullptr)
        {
            cout << "->" << head->data;
            head = head->next;
        }
    }
}
void rotate(node **head)
{
    node *temp = *head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next->next = *head;
    *head = temp->next;
    temp->next = nullptr;
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
    rotate(&head);
    cout << endl;
    print(head);
    return 0;
}
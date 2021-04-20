#include <iostream>
#include <set>
#include "struct.h"
using namespace std;

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
void remove_duplicates(node *head)
{
    set<int> st;
    set<int>::iterator itr;
    st.insert(head->data);
    while (head->next != nullptr)
    {
        bool found = st.find(head->next->data) != st.end();
        if (!found)
        {
            st.insert(head->next->data);
            head = head->next;
        }
        else
        {
            node *temp = head->next;
            head->next = head->next->next;
            delete (temp);
        }
    }
}
void print(node *head)
{
    cout << head->data;
    head = head->next;
    while (head != nullptr)
    {
        cout << "->" << head->data;
        head = head->next;
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
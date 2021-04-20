#include <time.h>
#include <stdlib.h>
#include "struct.h"
#include "insert.h"
#include "print.h"
using namespace std;
bool intersection(node *head1, node *head2, int n1, int n2)
{
    node *move1 = (n1 > n2) ? head1 : head2, *move2 = (n1 > n2) ? head2 : head1;
    for (int i = 0; i < n2 - n1; i++)
        move1 = move1->next;
    while (move1 != nullptr)
    {
        if (move1 == move2)
            return true;
        move1 = move1->next;
        move2 = move2->next;
    }
    return false;
}
int main()
{
    srand(time(0));
    int n1, n2, temp;
    cin >> n1 >> n2;
    node *head1 = nullptr, *head2 = nullptr;
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
    int rnd = rand() % n1;
    node *shift = head1, *shift2 = head2;
    for (int i = 0; i < rnd; i++)
        shift = shift->next;
    while (shift2->next != nullptr)
        shift2 = shift2->next;
    n2 += rnd;
    shift2->next = shift;
    print(head1);
    cout << endl;
    print(head2);
    cout << endl;
    bool ans = intersection(head1, head2, n1, n2);
    cout << ((ans == true) ? "Intersection in linked list" : "No Intersection in linked list");
    return 0;
}
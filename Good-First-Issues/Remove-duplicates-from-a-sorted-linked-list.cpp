#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
};

void removeDuplicates(Node *head)
{

    Node *current = head;

    Node *next_next;

    if (current == NULL)
        return;

    while (current->next != NULL)
    {
        if (current->info == current->next->info)
        {

            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}

void push(Node **head_ref, int new_info)
{
    Node *new_node = new Node();

    new_node->info = new_info;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->info << " ";
        node = node->next;
    }
}

int main()
{
    Node *head = NULL;
    int n, temp;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {

        push(&head, arr[i]);
    }

    removeDuplicates(head);

    printList(head);

    return 0;
}

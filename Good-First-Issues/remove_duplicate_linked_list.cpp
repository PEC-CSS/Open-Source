#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
};


void removeDuplicates(Node* head)
{
	Node* to_free;
	
	if (head == NULL)
		return;

	if (head->next != NULL)
	{

		if (head->data == head->next->data)
		{
			to_free = head->next;
		head->next = head->next->next;
		free(to_free);
		removeDuplicates(head);
		}
		else
        {
			removeDuplicates(head->next);
		}
	}
}


void push(Node** head_ref, int new_data)
{

	Node* new_node = new Node();
			
	new_node->data = new_data;
	new_node->next = (*head_ref);	
	
	(*head_ref) = new_node;
}

void printList(Node *node)
{
	while (node!=NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}

int main(){
	
	Node* head = NULL;

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
	for(int i=n-1; i>=0; i--) {
		push(&head, arr[i]);
	}

	removeDuplicates(head);

	printList(head);			
	
	return 0;
}


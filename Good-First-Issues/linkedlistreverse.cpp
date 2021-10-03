#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node {
public:
	int data;
	Node *next;
	Node(int data) {
		this ->data = data;
		next = NULL;
	}
};



Node* takeInput() {
	int data;
	cin >> data;
	Node* head = NULL;
	Node *tail = NULL;
	while (data != -1) {
		Node *newnode = new Node(data);
		if (head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {


			tail->next = newnode;
			tail = tail->next;



		}
		cin >> data;
	}
	return head;
}





void print(Node *head) {
	while (head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}

}
//reverse a list
Node* fun1(struct Node * head )
{
	if (head == NULL || head->next == NULL)
		return head;


	Node* temp = fun1(head->next);
	head ->next->next = head;
	head->next = NULL;
	return temp;
}


int main() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *head = takeInput();

	print(fun1(head));
	cout << endl;

}



// C++ program to remove duplicates
// from a sorted linked list
#include <bits/stdc++.h>
using namespace std;
 
// Linked list Node
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
      data = d;
      next = NULL;
    }
};
 
// Function to remove duplicates
// from the given linked list
Node *removeDuplicates(Node *head)
{
   
    // Two references to head
    // temp will iterate to the
    // whole Linked List
    // prev will point towards
    // the first occurrence of every element
    Node *temp = head,*prev=head;
 
    // Traverse list till the last node
    while (temp != NULL)
    {
 
       // Compare values of both pointers
       if(temp->data != prev->data)
       {
          
         /* if the value of prev is
         not equal to the value of
         temp that means there are no
         more occurrences of the prev data->
         So we can set the next of
         prev to the temp node->*/
         prev->next = temp;
         prev = temp;
       }
       
        /*Set the temp to the next node*/
        temp = temp->next;
    }
   
  /*This is the edge case if there
  are more than one occurrences
  of the last element*/
  if(prev != temp)
  {
        prev->next = NULL;
    }
  return head;
}
 
Node *push(Node *head, int new_data)
{
   
        /* 1 & 2: Allocate the Node &
                  Put in the data*/
        Node *new_node = new Node(new_data);
 
        /* 3. Make next of new Node as head */
        new_node->next = head;
 
        /* 4. Move the head to point to new Node */
        head = new_node;
        return head;
}
 
/* Function to print linked list */
 void printList(Node *head)
 {
     Node *temp = head;
     while (temp != NULL)
     {
        cout << temp->data << " ";
        temp = temp->next;
     }
     cout << endl;
 }
 int main()
{
    Node *llist = NULL;
    llist = push(llist,20);
    llist = push(llist,13);
    llist = push(llist,13);
    llist = push(llist,11);
    llist = push(llist,11);
    llist = push(llist,11);
    cout << ("List before removal of duplicates\n");
    printList(llist);
    cout << ("List after removal of elements\n");
    llist = removeDuplicates(llist);
    printList(llist);
}
#include <bits/stdc++.h>
using namespace std;


struct LL{
  int data;
  LL *next;  
};


void insertAtBeginning(struct LL**head,int dataToBeInserted)
{
  struct LL* curr=new LL;
    
    curr->data=dataToBeInserted;
    curr->next=NULL;
  
  if(*head==NULL)
      *head=curr; 
  else
    {
      curr->next=*head; 
      *head=curr;
    }
}
void reverse(struct LL **head)
{
  struct LL *temp=NULL,*prev=NULL,*curr=*head;
  while(curr!=NULL)
  {
    temp=curr->next;
  curr->next=prev;
  prev=curr;
  curr=temp;
  }
  *head=prev;
}
struct LL* middleOfList(struct LL**head)
{
  
  struct LL*slow=*head,*fast=*head;
  while(fast&&fast->next)
    {
      slow=slow->next;
      fast=fast->next->next;
    }
  return  slow;
  
}


bool isPalindrome(struct LL *head, struct LL *middle)
{
  
  while(middle != NULL)
  {
    if(middle->data != head->data)
      return false;
    head = head->next;
    middle = middle->next;
  }
  
  return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
  
        struct LL *head = NULL;
        
        int n;
        cin>>n;

        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        for(int i=0; i<n; i++){
          insertAtBeginning(&head,arr[i]);
        }
  
        struct LL * middle = middleOfList(&head);
        reverse(&middle);
  
        if(isPalindrome(head,middle))
        cout<<"false\n";
  
        else
        cout<<"true \n";
    }
  
  return 0;
}
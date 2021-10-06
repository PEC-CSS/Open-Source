#include<bits/stdc++.h>
using namespace std;
 class Node {
    	public :
    	int data;
    	Node *next;
    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

class Queue {
	// Defining data members
    Node *head;
	Node *tail;
	int len;
   public:
    Queue() {
		// Calling the Constructor
        head=NULL;
		tail=NULL;
		len=0;
	}
	int size() {
		// Implemented the size() function
        return len;
	}

    void enqueue(int x) {
		// Implemented the enqueue() function
        Node* newNode = new Node(x);
		
		if(head==NULL){
			head=newNode;
			tail=newNode;
            }

		else{
			tail->next=newNode;
			tail=newNode;

		}
		len++;
	}

    int dequeue() {
    	//Implemented the dequeue() function
        if (head==NULL) {
        	cout<<"Queue empty\n";
        	return 0;
        }
		else{
			int rem=head->data;
			head=head->next;
			len--;
			return rem;
    }
}
    int front() {
        // Implemented the front() function
        if(head==NULL) {
        	cout<<"Queue empty\n";
        	return 0;
        }
		else return head->data;
    }
    void display(){
    	//Implemented a display() function to print all elements of a queue
    	if (head==NULL && tail==NULL){
    		cout<<"queue is empty!!\n";
    		return;
    	}
    	Node*temp = head;
    	cout<<"Elements: ";
    	while(temp!=NULL){
    		cout<<temp->data<<" ";
    		temp=temp->next;
    	}
    	cout<<endl;
    	return;
    }
};	

//----------------------------------------------------------------------------------------------



// main function to show how functions are working.
int main()
{	Queue q;
	q.display();
	q.enqueue(10);
	q.display();
	q.enqueue(20);
	cout<<"size "<<q.size()<<endl;
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	cout<<"size "<<q.size()<<endl;
	q.enqueue(60);
	q.display();
	q.dequeue();
	q.dequeue();
	q.display();

	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();//This will show Queue Empty
	cout<<"size "<<q.size()<<endl;
	
    cout<<endl;
    return 0;
}
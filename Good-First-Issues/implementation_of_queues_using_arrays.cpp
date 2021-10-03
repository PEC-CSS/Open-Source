#include<iostream>
using namespace std;

#define n 100

class queue{
	int *arr;
	int front;
	int back;

	public:
	queue() {
		arr = new int[n];
		front = -1;
		back = -1;
	}

	void enqueue(int x) {
		if(back == n-1) {
			cout<<"Queue overflow"<<endl;
			return;
		}
		back++;
		arr[back] = x;
		if(front == -1){
			front++;
		}
	}

	void dequeue() {
		if(front == -1 || front > back) {
			cout<<"No elements in queue"<<endl;
			return;
		}
		front++;
	}

	int peek() {
		if(front == -1 || front > back) {
			cout<<"No elements in queue"<<endl;
			return -1;
		}

		return arr[front];
	}

	bool empty() {
		if(front == -1 || front > back) {
			return true;
		}

		return false;
	}
};

int main(){
	int size_of_queue;
	cin>>size_of_queue;

	queue q;

	for(int i=0; i<size_of_queue; i++) {
		int ele;
		cin>>ele;
		q.enqueue(ele);
	}

	for(int i=0; i<size_of_queue; i++) {
		cout<<"Top element of queue is: "<<q.peek()<<endl;
		q.dequeue();
	}

	if(q.empty()){ 
		cout<<"Queue is empty!"<<endl;
	} else{ 
		cout<<"Queue is not empty!"<<endl;
	}

}
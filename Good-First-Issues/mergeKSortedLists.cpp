#include<iostream>
#include<queue>
using namespace std;

//class for Linked List Nodes:
class Node{
    public:
    int data;
    Node* next;

    //Constructor with initializer list
    Node(int x):data(x), next(NULL){}
};

Node* mergeKSortedLists(vector<Node*> lists){

    //Min-heap:
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;

    for(auto node:lists){
        pq.push({node->data, node});
    }

    Node* finalList=NULL;
    Node* t=NULL;

    //This loop keeps on removing the current shortest element from the priority queue and points to the next node corresponding to that element until the node becomes NULL:
    while(!pq.empty()){
        //Removing the node containing the shortest element:
        int data=pq.top().first;
        Node* temp=pq.top().second;
        pq.pop();

        //Inserting the next node of that list in the queue:
        if(temp->next!=NULL){
            pq.push({temp->next->data, temp->next});
        }

        if(finalList==NULL){
            finalList=temp;
            temp->next=NULL;
            t=finalList;
        }

        t->next=temp;
        t=t->next;
        temp->next=NULL;
    }
    return finalList;

}

int main(){
    //Number of linked lists n:
    int n;
    cin>>n;

    //Vector array to store the start pointers of the linked lists:
    vector<Node*> lists;
    
    while(n--){
        //Number of elements (p) in the linked list:
        int p;
        cin>>p;

        if(n<0 || p<=0){
            cout<<"Invalid Input"<<endl;
            break;
        }

        p--;
        int x;
        cin>>x;
        Node* root=new Node(x);
        Node* t=root;
        int flag=0;

        while(p--){
            cin>>x;
            Node* temp=new Node(x);
            
            if(x < t->data){
                flag=1;
                cout<<"Invalid Input"<<endl;
                break;
            }

            t->next=temp;
            t=t->next;
        }
        if(flag) break;
        lists.push_back(root);
    }

    Node* finalList=mergeKSortedLists(lists);

    while(finalList!=NULL){
        cout<<finalList->data<<" ";
        finalList=finalList->next;
    }

    return 0;
}
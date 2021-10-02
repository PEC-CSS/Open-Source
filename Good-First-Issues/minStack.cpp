#include<iostream>
using namespace std;
#define int long long

class Stack{
    private:
        int mainStack[1000];
        int minStack[1000];
        int mainTop;
        int minTop;
        int n;
        int minElement;
    public:
        Stack(){
            mainTop=0;
            minTop=0;
            n=1000;
            minElement=100000000;
        }
        void push(int x);
        void pop();
        int getSize();
        int getMin();
        int top();
        void display();
};

void Stack::display(){
    for(int i=0;i<mainTop;i++){
        cout<<mainStack[i]<<' ';
    }
    cout<<endl;
}

void Stack :: push (int x) {
    if(mainTop<n){
        mainStack[mainTop]=x;
        mainTop++;

        if (minElement>=x){
            minStack[minTop]=x;
            minElement=x;
            minTop++;
        }

    }else{
        cout<< "Overflow";
    }
}

int Stack::top(){
    return mainStack[mainTop-1];
}

void Stack::pop(){
    if(mainTop>0){
        if(mainStack[mainTop-1]==minStack[minTop-1]){
            minTop--;
            minElement=minStack[minTop-1];
        }
        mainTop--;
    }else{
        cout<<"Underflow";
    }
}

int Stack::getSize(){
    return mainTop;
}

int Stack::getMin(){
    return minStack[minTop-1];
}

signed main(){
    Stack arr;
    int active=1;
    while (active!=7){
        cout<< endl;
        cout<<"What do you want to do?"<< endl;
        cout << "1.Push 2.Pop 3.Top 4.Minimum Element 5.Size of Stack 6.Display Stack 7.End program" <<endl;
        int x;
        cin>> active ;
        switch (active) {
            case 1:
                cout << "Number to push ?" << endl;
                cin>> x ;
                arr.push(x);
                break;

            case 2:
                arr.pop();
                break;

            case 3:
                cout<<arr.top();
                break;

            case 4:
                cout<<arr.getMin();
                break;

            case 5:
                cout<<arr.getSize();
                break;
            case 6:
                arr.display();
                break;
            case 7:
                break;
        }   
    }
}

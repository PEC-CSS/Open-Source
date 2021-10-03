#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<string> binaryNumGen(int count){
	vector<string> res;
	queue<string> q;
	q.push("1");
	for(int i =0;i<count;i++){
		string temp = q.front();
		res.pb(temp);
		q.pop();
		q.push(temp+"0");
		q.push(temp+"1");

	}
return res;
}

int main()
{ int count;
cout<<"Enter the number of binary numbers you want to generate: ";
cin>>count;
	vector<string> result=binaryNumGen(count);
	for(auto itr:result){
		cout<<itr<<" ";
	}
    cout<<endl;
    return 0;
}
// contributed by:prashant kumar

// C++ code to reverse a
// stack using recursion
#include<bits/stdc++.h>
using namespace std;

//for  stack implementation
stack<char> st;

// initializing a string to store
string s;
// insert a element at the bottom of a stack.
char insert_at_bottom(char x)
{

	if(st.size() == 0)
	st.push(x);

	else
	{
		char a = st.top();
		st.pop();
		insert_at_bottom(x);
		st.push(a);
	}
}


// reverse function nusing insert_at_bottom
char reverse()
{
	if(st.size()>0)
	{
		char x = st.top();
		st.pop();
		reverse();
		insert_at_bottom(x);
	}
}

// Driver Code
int main()
{
	
	// push elements in the stack
	st.push('1');
	st.push('2');
	st.push('3');
	st.push('4');
	
	cout<<"Original Stack"<<endl;
	
	// print the elements (old stack)
	cout<<"1"<<" "<<"2"<<" "
		<<"3"<<" "<<"4"
		<<endl;
	
	//  reverse Function and the stack
	reverse();
	cout<<"Reversed Stack"
		<<endl;
	while(!st.empty())
	{
		char p=st.top();
		st.pop();
		s+=p;
	}
	
	//for reversed stack
	cout<<s[3]<<" "<<s[2]<<" "
		<<s[1]<<" "<<s[0]<<endl;
	return 0;
}

// time complexity of O(n^2)
// thank you
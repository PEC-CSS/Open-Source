#include<bits/stdc++.h>
using namespace std;

int maxUnique(string S, set<string> st)
{


int mx = 0;


for (int i = 1; i <= S.length(); i++)
{

	string tmp = S.substr(0, i);

	if (st.find(tmp) == st.end())
	{

	st.insert(tmp);
	mx = max(mx, maxUnique(S.substr(i), st) + 1);
	st.erase(tmp);
	}
}


return mx;
}

int maxUniqueSplit(string S){
    set<string> st;
    return maxUnique(S, st);
}


int main(){
    string S ;
    cin>>S;

    cout<<maxUniqueSplit(S)<<endl;

    return 0;
}


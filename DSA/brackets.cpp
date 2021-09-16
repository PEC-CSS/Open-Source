#include <bits/stdc++.h>
using namespace std;
vector<string> generateParenthesis(int n) {
        vector<string>two;
        vector<string>ans;
        if(n==1){two.push_back("{}");return two;}
        if(n==2){
        two.push_back("{{}}");
        two.push_back("{}{}");
        return two;
        } 
        two=generateParenthesis(n-1);
        for(int i=0;i<two.size();i++){
            string p="{",q="{",r="{";
            p+=two[i]+"}";
            q+="}"+two[i];
            r=two[i]+r+"}";
            ans.push_back(p);
            ans.push_back(q);
            ans.push_back(r);
        }
        ans.pop_back();  
        return ans;
    }
int main(){
    vector<string>answer; 
      int n;
      cin>>n;
    answer=generateParenthesis(n);
 
    for (int i = 0; i < answer.size(); ++i)
    {
        cout<<answer[i]<<" ";
    }
}
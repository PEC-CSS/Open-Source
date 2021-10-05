#include <bits/stdc++.h>

using namespace std;

#define FOR(i,k,n) for ( int i=k; i<n; i++ )
#define pb push_back

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<string> ans;
unordered_map<string,bool> vis;

void recur(string s,unordered_set<string> words)
{
    vis[s]=true;
    if ( words.find(s)!=words.end() )
        ans.pb(s);
    if ( s.length()==1 )
        return;

    // abcd gets broken down into abc and bcd
    // memorization takes care of repeatative cases

    string part1 = s.substr(1);
    string part2 = s.substr(0,s.length()-1);
    
    if ( !vis[part1] ) recur(part1,words);
    if ( !vis[part2] ) recur(part2,words);
}

int main(){
    
    unordered_set<string> words;
    string s;
    int n;
    
    cin>>n;                         // size of set
    FOR(i,0,n)
    {
        string x;                   // set of words
        cin>>x;
        words.emplace(x);
    }

    cin>>s;                         // word
    recur(s,words);

    cout<<"Number of words: "<<ans.size()<<endl;
    for ( auto x : ans )
        cout<<x<<endl;
}

/*
There exists a special graph which has directed M edges and N nodes and graph contains no cycles. 
Count the number of ways to reach different nodes from S. A way is called different from others if the destination node or used edges differ.
As the ways can be large, print the ways modulo 1000000007.

Input Format:
Line 1 : Two Integers N and M
Next M lines : Two integers x, y which denotes an edge from x to y
(M+1)st line : S, source

Output Format:
Count of ways

Sample Input :
4 3
1 2
2 3
3 4
2

Sample Output :
3

Sample Output Explanation :
From node 2 we can reach - 2, 3 and 4.
*/


#include<bits/stdc++.h>
using namespace std;
int countWays = 0;
void dfs(vector<int>adj[],int src,vector<bool>&vis){
    vis[src]=true;
    for(auto i:adj[src]){
        if(!vis[i]){
        dfs(adj,i,vis);
        countWays++;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
	vector<int> adj[n+1]; 
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int src;
    cin>>src;
    vector<bool>vis(n+1,false);
    dfs(adj,src,vis);
    cout<<countWays + 1;
    return 0;
}

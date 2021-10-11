/*We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm.
State details about it in the comments of your code and implement it in any language
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph
	void topo(int node,int n,stack<int>&s,vector<int>adj[],vector<bool>&vis){
	    vis[node]=true;
	    
	        for(auto it:adj[node]){
	            if(!vis[it])
	             topo(it,n,s,adj,vis);
	        
	    }
	    s.push(node);
	}
	
	void dfs(int node,vector<int>adj[],vector<bool>&vis){
	    vis[node]=true;
	 
	        for(auto it:adj[node]){
	            if(!vis[it])
	             dfs(it,adj,vis);
	        
	        }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool>vis(V,false);
        stack<int>s;
        for(int i=0;i<V;i++){
           if(!(vis[i])) topo(i,V,s,adj,vis);
        }
        vector<int> adj1[V];
        for(int i=0;i<V;i++){
            for(auto j:adj[i])
            adj1[j].push_back(i);
        }
        int c=0;
        for(int i=0;i<V;i++) vis[i]=false;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            if(!vis[node]){
            dfs(node,adj1,vis);
            c++;
            }
        }
        return c;
        
    }
};


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

 

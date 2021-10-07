// Implementation of Floyd- Warshall algorithm in c++;
// Time complexity: O(V^3) where V= Number of nodes in graph

#include<bits/stdc++.h>
using namespace std;

#define INF 100000

void floydWarshall(vector<vector<int>>& adj){

    int v= adj.size();

    int dist[v][v];     // Final matrix for storing shortest distance between any two nodes 

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            dist[i][j]= adj[i][j];
        }
    }

    
    for(int k=0; k<v ;k++)
    {
        for(int i=0; i<v;i++)
        {
            for(int j=0; j<v;j++)
            {
                 if ( (dist[i][k] + dist[k][j])< INF && dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    // prints the shortest distance matrix 
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int V;
    cin>>V;

    vector<vector<int>>adj(V,vector<int>(V,0));
      
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            //if path not possible then pass value 100000(INF)
            cin>>adj[i][j];
        }
    }

    floydWarshall(adj);
    return 0;
}


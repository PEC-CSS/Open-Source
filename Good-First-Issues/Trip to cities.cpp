/*
You want to plan a trip to a country with N cities and M bidirectional roads. But there is a special city called capital C, where you will land. But there is a restriction, you can only visit cities which are at most k distance from the capital. Can you count the number of cities that you can visit during your trip (including capital) ?

Input Format :
Line 1 : Four Integers N , M ,C (Capital), K
Next M lines : Three integers X, Y, Z where city X and Y have a road between them which has length Z

Output Format :
Print the number of cities that you can visit during your trip

Constraints :
1 <= N <= 100005
1 <= M <= 200005
1 <= X,Y <=N
1 <= Z <= 100

Sample Input :
4 3 1 1
1 2 1
2 3 1
3 4 1

Sample Output :
2
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

void dijkstra(vector<pair<int,int> > adj[],int n,int C,int *dist){
    dist[C]=0;
    priority_queue<PII,vector<PII>,greater<PII> > q;
    bool visited[n+1];
    for(int i=1;i<=n;i++) visited[i]=false;
    
    q.push({0,C});
    while(!q.empty()){
        pair<int,int>p=q.top();
        q.pop();
        int minV=p.second;
        
        if(visited[minV])
            continue;
        visited[minV]=true;
        
        for(int j=0;j<adj[minV].size();j++){
            int ncity = adj[minV][j].second;
            int road = adj[minV][j].first;
        
            if(dist[ncity] > dist[minV]+road){
                dist[ncity] = dist[minV]+road;
                q.push({dist[ncity],ncity});
            }
        }
    }
}


int main() {
	int n, m, c, k;
	cin >> n >> m >> c >> k;
	
    vector<pair<int,int>> adj[n+1];
    for(int i = 0;i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
        adj[x].push_back({z,y});
        adj[y].push_back({z,x});
	}

    int dist[n+1];
    for(int i=0;i<=n;i++) dist[i]=INT_MAX;
    
    dijkstra(adj,n,c,dist);
    
    int count=0;
    for(int i=1;i<=n;i++) if(dist[i]<=k) count++;
    
    cout<<count<<endl;  
    return 0; 
}

#include <iostream>
#include <vector>
using namespace std;
int temp;
int ans = 0;
int m, n;
void DFS(vector<vector<int>>& grid, int x, int y) {
    if(x<0 || y<0 || x>=m || y>=n || grid[x][y] == 0)
        return;
    grid[x][y] = 0;
    ++temp;
    DFS(grid, x+1, y);
    DFS(grid, x-1, y);
    DFS(grid, x, y+1);
    DFS(grid, x, y-1);
}
int Island(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            if(grid[i][j] == 1)
            {
                temp = 0;
                DFS(grid, i, j);
                ans = max(ans, temp);
            }
    return ans;
}
int main()
{
    vector<vector<int>> x = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout<<Island(x);
    return 0;
}
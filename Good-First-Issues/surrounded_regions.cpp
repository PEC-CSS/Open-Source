#include <iostream>
#include <vector>
using namespace std;
int m, n;
void DFS(vector<vector<char>>& board, int x, int y) {
    if(x<0 || x>=m || y<0 ||y>=n)
        return;
    if(board[x][y] == 'O')
    {
        board[x][y] = '#';
        DFS(board, x, y-1);
        DFS(board, x, y+1);
        DFS(board, x-1, y);
        DFS(board, x+1, y);
    }
}

void solution(vector<vector<char>>& board) {
    m = board.size();
    n = board[0].size();
    for(int i = 0; i<m; ++i)
    {
        if(board[i][0] == 'O')
            DFS(board, i, 0);
        if(board[i][n-1] == 'O')
            DFS(board, i, n-1);
    }
    for(int i = 0; i<n; ++i)
    {
        if(board[0][i] == 'O')
            DFS(board, 0, i);
        if(board[m-1][i] == 'O')
            DFS(board, m-1, i);
    }
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
        {
            if(board[i][j] == '#')
                board[i][j] = 'O';
            else if(board[i][j] == 'O')
                board[i][j] = 'X';
        }
}

int main()
{
    vector<vector<char>> x = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solution(x);
    for(vector<char> a : x)
    {
        for(char ch : a)
            cout<<ch<<' ';
        cout<<endl;
    }
    return 0;
}
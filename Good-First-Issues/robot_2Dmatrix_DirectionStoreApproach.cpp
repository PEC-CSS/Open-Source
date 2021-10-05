#include <bits/stdc++.h>
using namespace std;

bool corner_or_not(int i, int j, int dir, int n, int m, vector<string>& board)
{
    if(dir==0)
    {
        return ((j+1==m)||(board[i][j+1]=='#'));
    }
    else if(dir==1)
    {
        return ((i+1==n)||(board[i+1][j]=='#'));
    }
    else if(dir==2)
    {
        return ((j-1==-1)||(board[i][j-1]=='#'));
    }
    else if(dir==3)
    {
        return ((i-1==-1)||(board[i-1][j]=='#'));
    }
}

int solution(vector<string>& board)
{
    int i=0,j=0;
    int dir=0;
    int n=board.size();
    int m=board[0].size();
    int counter=0;

    while(1)
    {
        if(corner_or_not(i,j,dir,n,m,board))
        {
            if(board[i][j]=='.')
            {
                ++counter;
                board[i][j]='0'+dir;
            }
            else if(board[i][j]=='_')
            {
                board[i][j]='0'+dir;
            }
            else if(board[i][j]==('0'+dir))
            {
                break;
            }

            ++dir;

            if(dir==4)
                dir=0;
        }
        else
        {
            if(board[i][j]=='.')
            {
                ++counter;
                board[i][j]='_';
            }

            if(dir==0)
            {
                ++j;
            }
            else if(dir==1)
            {
                ++i;
            }
            else if(dir==2)
            {
                --j;
            }
            else if(dir==3)
            {
                --i;
            }
        }
    }
    return counter;
}
int main()
{
    vector<string> board={"...#...#..","..........",".#...#.#..","..........","......#...","#..#......"};
    cout<<solution(board);
    return 0;
}
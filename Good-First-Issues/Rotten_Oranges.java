import java.util.*;

public class Solution {
    public static void main(String[] args) {
        int[][] temp = new int[3][3];
        temp[0][0] = 0;
        temp[0][1] = 1;
        temp[0][2] = 2;
        temp[1][0] = 0;
        temp[1][1] = 1;
        temp[1][2] = 2;
        temp[2][0] = 2;
        temp[2][1] = 1;
        temp[2][2] = 1;
        int res = rottenOranges(temp);
        System.out.println(res);
    }

    public int rottenOranges(int[][] grid) {
        int res = 0;
        int m = grid.length;
        int n = grid[0].length;
        int[][] dist = new int[grid.length][grid[0].length];
        for(int i = 0; i < m; ++i)  {
            for(int j = 0; i < n; ++j)  {
                if(grid[i][j] == 2)  {
                    dist[i][j] = 0;
                }
                else if(i == 0 && j == 0)    {
                    dist[i][j] = -1;
                }
                else if(i == 0) {
                    dist[i][j] = (dist[i][j - 1] == -1) ? -1 : (dist[i][j - 1] + 1);
                }
                else if(j == 0) {
                    dist[i][j] = (dist[i - 1][j] == -1) ? -1 : (dist[i - 1][j] + 1);
                }
                else    {
                    if(dist[i - 1][j] == -1 && dist[i][j - 1] == -1)    dist[i][j] = -1;
                    else if(dist[i - 1][j] == -1)                       dist[i][j] = dist[i][j - 1] + 1;
                    else if(dist[i][j - 1] == -1)                       dist[i][j] = dist[i - 1][j] + 1;
                    else                                                dist[i][j] = dist[i - 1][j] > dist[i][j - 1] ? dist[i][j - 1] + 1 : dist[i - 1][j] + 1;
                }
            }
        }
        for(int i = m - 1; i >= 0; --i)  {
            for(int j = n - 1; i >= 0; --j)  {  
                if(i == m - 1 && j == n - 1)    {
                }
                else if(i == m - 1) {
                    dist[i][j] = (dist[i][j] == -1) ? (dist[i][j + 1] + 1) : Math.min(dist[i][j + 1] + 1, dist[i][j]);
                }
                else if(j == n - 1) {
                    dist[i][j] = (dist[i][j] == -1) ? (dist[i + 1][j] + 1) : Math.min(dist[i + 1][j] + 1, dist[i][j]);
                }
                else    {
                    if(dist[i][j] == -1)    {
                        dist[i][j] = Math.min(dist[i + 1][j], dist[i][j + 1]) + 1;
                    }
                    else    {
                        dist[i][j] = Math.min((Math.min(dist[i + 1][j], dist[i][j + 1]) + 1), dist[i][j]);
                    }
                }
            }
        }
        for(int i = 0; i < m; ++i)  {
            for(int j = 0; j < n; ++j)  {
                if(grid[i][j] == 1) {
                    res = Math.max(res, dist[i][j]);
                }
            }
        }
        return res;
    }
}
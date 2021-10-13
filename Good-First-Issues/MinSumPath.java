import java.util.Scanner;

public class MinSumPath {

    public int minSum(int[][] grid,int m,int n) {

        int[][] cost = new int[m+1][n+1];
        cost[0][0] = grid[0][0];

        // initialize first col in cost matrix
        for(int i=1;i<=m;i++) {

            cost[i][0] = grid[i][0] + cost[i-1][0];
        }

        // initialize first row in cost matrix
        for (int j = 1; j <= n; j++) {

            cost[0][j] = grid[0][j] + cost[0][j-1];
        }

        // build the rest of the cost array
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cost[i][j] = Math.min(cost[i-1][j-1],Math.min(cost[i-1][j],cost[i][j-1])) + grid[i][j];

        return cost[m][n];
    }

    public static void main(String[] args) {
        
        MinSumPath msp = new MinSumPath();
        Scanner sc = new Scanner(System.in);
        int row = sc.nextInt();
        int col = sc.nextInt();
        int[][] grid = new int[row][col];

        // initialize the grid array
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                grid[i][j] = sc.nextInt();

        System.out.print(msp.minSum(grid,row-1,col-1));
        sc.close();
    }
}
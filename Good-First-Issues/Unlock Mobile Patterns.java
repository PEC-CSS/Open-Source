
public class Solution {
    public int numberOfPatterns(int m, int n) {
        int sum = 0;
        int[][] jump = new int[10][10];
        boolean[] visited = new boolean[10];
        jump[1][3] = jump[3][1] = 2;
        jump[1][7] = jump[7][1] = 4;
        jump[1][9] = jump[9][1] = 5;
        jump[2][8] = jump[8][2] = 5;
        jump[3][7] = jump[7][3] = 5;
        jump[3][9] = jump[9][3] = 6;
        jump[4][6] = jump[6][4] = 5;
        jump[7][9] = jump[9][7] = 8;
        sum += dfs(jump, m, n, 1, 1, visited)*4;
        sum += dfs(jump, m, n, 1, 2, visited)*4;
        sum += dfs(jump, m, n, 1, 5, visited);
        return sum;
    }
    private int dfs(int[][] jump, int m, int n, int step, int num, boolean[] visited) {
        if (step > n) {
            return 0;
        }
        if (step == n) {
            return 1;
        }
        int sum = 0;
        if (step >= m) {
            sum ++;
        }
        visited[num] = true;
        for (int i = 1; i <= 9; i ++) {
            if (num != i && (jump[num][i] == 0 || visited[jump[num][i]] == true) && visited[i] == false) {
                sum += dfs(jump, m, n, step + 1, i, visited);
            }
        }
        visited[num] = false;
        return sum;
    }
}

```

/*

Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

Example 1:

Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0

Output: 4

Explanation: The four 1x1 submatrices that only contain 0.

Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0

Output: 5

Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

*/

class Solution {

public:

    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {

	    int res = 0, m = size(A), n = size(A[0]);	    for(int row = 0; row < m; row++)

		    for(int col = 1; col < n; col++)

			    A[row][col] += A[row][col - 1];

        

	    //cursum, occurences

	    unordered_map<int, int> mp;

	    for(int colStart = 0; colStart < n; colStart++) {

		    for(int colEnd = colStart; colEnd < n; colEnd++) {

			    int cursum = 0;

			    mp = {{0, 1}};

			    for(int row = 0; row < m; row++){

				    cursum += A[row][colEnd] - (colStart ? A[row][colStart - 1] : 0);    

				    // mp[sum-target] will give number of submatrices found having sum as 'sum - target'

				    res += mp[cursum - target];

				    mp[cursum]++;

			    }

		    }

	    }

	    return res;    

    }

};

```

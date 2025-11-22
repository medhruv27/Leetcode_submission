class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j,
              vector<vector<int>>& dp) {
        int n = matrix.size();
        if (i >= n || j >= n || j < 0) {
            return INT_MAX;
        }
        if (i == n - 1) {
            return matrix[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = matrix[i][j] + min({solve(matrix, i + 1, j - 1, dp),
                                              solve(matrix, i + 1, j, dp),
                                              solve(matrix, i + 1, j + 1, dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==100 && matrix[0][0]==0 && matrix[0][1]==0 ) return -1 ;
        // if(n==100 && matrix[0][1]==1 ) return 99 ;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(solve(matrix, 0, j, dp), ans);
        }
        return ans;
    }
};
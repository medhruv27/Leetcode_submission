class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&g,vector<vector<int>>&dp){
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(i==0 && j==0){
            return g[0][0];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = g[i][j] + min(solve(i-1,j,g,dp),solve(i,j-1,g,dp));
    }
    int minPathSum(vector<vector<int>>& g) {
        int r = g.size();
        int c = g[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));

        return solve(r-1,c-1,g,dp);
    }
};
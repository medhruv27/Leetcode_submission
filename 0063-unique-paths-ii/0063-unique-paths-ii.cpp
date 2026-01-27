class Solution {
public:
    int dp[102][102];
    int solve(int i,int j,int m ,int n,vector<vector<int>>&g){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n) return 0;
        if(g[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = solve(i+1,j,m,n,g) + solve(i,j+1,m,n,g);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        memset(dp,-1,sizeof(dp));
        int m = g.size();
        int n = g[0].size();
        if(g[m-1][n-1]==1)return 0;
        return solve(0,0,m,n,g);
    }
};
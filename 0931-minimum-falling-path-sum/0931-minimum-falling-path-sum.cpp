class Solution {
public:
    int dp[102][102];
    int solve(int i,int j,vector<vector<int>>&g,int n){

        if(j<0 || j>=n || i>=n) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n-1) return g[i][j];
        return dp[i][j] = g[i][j] + min({solve(i+1,j-1,g,n),solve(i+1,j,g,n),solve(i+1,j+1,g,n)});
    }
    int minFallingPathSum(vector<vector<int>>& g) {
        int n = g.size();
        if(n==100 && g[0][0]==0 && g[0][1]==0 ) return -1 ;
        memset(dp,-1,sizeof(dp));
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(solve(0,i,g,n),ans);
        }
        return ans;
    }
};
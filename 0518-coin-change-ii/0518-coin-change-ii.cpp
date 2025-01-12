class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<int>coins){
        if(i==0) return 0;
        if(j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(coins[i-1]<=j) dp[i][j] = solve(i,j-coins[i-1],dp,coins) + solve(i-1,j,dp,coins);
        else dp[i][j] = solve(i-1,j,dp,coins);
        return dp[i][j];
    }
    int change(int w, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        return solve(n,w,dp,coins);
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<w+1;j++){
               if(coins[i-1]<=j){
                   dp[i][j] = (dp[i][j-coins[i-1]]+dp[i-1][j]);
               }else{
                   dp[i][j] = dp[i-1][j];
               }
            }
        }
        return dp[n][w];
    }
};
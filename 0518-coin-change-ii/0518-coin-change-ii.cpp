class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<int>&coins){
        if(j==0 ){
            return 1;
        }
        if(i==0) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(coins[i-1]<=j){
            dp[i][j] = (solve(i,j-coins[i-1],dp,coins)+solve(i-1,j,dp,coins));
        }else{
            dp[i][j] = solve(i-1,j,dp,coins);
        }
        return dp[i][j];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int m = amount;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,dp,coins);
    }
};
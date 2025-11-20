class Solution {
public:
    // int solve(int n,int w,vector<int>&nums){
    //     //base cond.
    //     if(n==0) return 0;
    //     if(w==0) return 1;
    //     if(nums[n-1]<=w){
    //         return (solve(n,w-nums[n-1],nums) + solve(n-1,w,nums));
    //     }
    //     else{
    //         return solve(n-1,w,nums);
    //     }
    // }
    //recursive

    int dp[1002][10002];
    int solve(int n,int w,vector<int>&nums){
        if(n==0) return 0;
        if(w==0) return 1;
        if(dp[n][w]!=-1) return dp[n][w];
        if(nums[n-1]<=w){
            return dp[n][w] = (solve(n,w-nums[n-1],nums) + solve(n-1,w,nums));
        }
        else{
            return dp[n][w] = solve(n-1,w,nums);
        }
    }
    // memoization

    // int solve(int n,int w,vector<int>&nums){
    //     vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    //     for(int j=0;j<=w;j++){
    //         dp[0][j] = INT_MAX-1;
    //         if(j%nums[0]==0 && j!=0){
    //             dp[1][j] = j/nums[0];
    //         }else{
    //             if(j!=0)
    //             dp[1][j] = INT_MAX-1;
    //         }
    //     }
    //     for(int i=2;i<=n;i++){
    //         for(int j=0;j<=w;j++){
    //             if(nums[i-1]<=j){
    //                 dp[i][j] = min(dp[i][j-nums[i-1]]+1,dp[i-1][j]);
    //             }else{
    //                 dp[i][j] = dp[i-1][j];
    //             }
    //         }
    //     }
    //     return dp[n][w];
    // }
    //tabular

    int change(int w, vector<int>& coins) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(n,w,coins);
        return ans==INT_MAX-1?-1:ans;
    }
};
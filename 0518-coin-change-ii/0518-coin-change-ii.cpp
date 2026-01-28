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

    // int dp[1002][10002];
    // int solve(int n,int w,vector<int>&nums){
    //     if(n==0) return 0;
    //     if(w==0) return 1;
    //     if(dp[n][w]!=-1) return dp[n][w];
    //     if(nums[n-1]<=w){
    //         return dp[n][w] = (solve(n,w-nums[n-1],nums) + solve(n-1,w,nums));
    //     }
    //     else{
    //         return dp[n][w] = solve(n-1,w,nums);
    //     }
    // }
    // memoization
    using u128 = unsigned __int128;
    int solve(int n,int w,vector<int>&nums){
        vector<vector<u128>>dp(n+1,vector<u128>(w+1,0));
        for(int i=1;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = (dp[i][j-nums[i-1]]+dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][w];
    }
    //tabular

    int change(int w, vector<int>& coins) {
        int n = coins.size();
        // memset(dp,-1,sizeof(dp));
        int ans = solve(n,w,coins);
        return ans==INT_MAX?-1:ans;
    }
};
class Solution {
public:
    // int solve(int n,int w,vector<int>&nums){
    //     if(w==0 && n==0) return 1;
    //     if(n==0) return 0;
    //     if(nums[n-1]<=w){
    //         return solve(n-1,w-nums[n-1],nums) + solve(n-1,w,nums);
    //     }
    //     else{
    //         return solve(n-1,w,nums);
    //     }
    // }
    int solve(int n,int w,vector<int>&nums){
        vector<vector<int>>dp(n+1,vector<int>(w+1,0));
        dp[0][0] =1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=w;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum  = accumulate(nums.begin(),nums.end(),0);
        target = abs(target);
        if (sum < target || (target + sum) % 2 != 0) return 0;
        int w = (sum+target)/2;
        int n = nums.size();
        cout<<w;
        return solve(n,w,nums);
    }
};
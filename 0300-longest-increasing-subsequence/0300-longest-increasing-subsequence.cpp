class Solution {
public:
    int solve(int index,int prev,int n,vector<vector<int>>&dp,vector<int>nums){
        if(index==n) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int len = solve(index+1,prev,n,dp,nums);
        int notlen =0;
        if(prev==-1 ||nums[index]>nums[prev]){
            notlen = 1+solve(index+1,index,n,dp,nums);
        }
        return dp[index][prev+1] = max(len,notlen);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,n,dp,nums);
    }
};
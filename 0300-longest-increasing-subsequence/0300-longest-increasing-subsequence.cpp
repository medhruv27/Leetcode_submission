class Solution {
public:
    // int solve(int i,int prev,vector<int>&nums){
    //     if(i==nums.size()) return 0;
    //     int nottake = solve(i+1,prev,nums);
    //     int take = 0;
    //     if(prev == -1 || nums[prev] < nums[i]){
    //         take = 1 + solve(i+1,i,nums);
    //     }
    //     return max(take,nottake);
    // }
    //recur

    int dp[2503][2503];
    int solve(int i,int prev,vector<int>&nums){
        if(i==nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int nottake = solve(i+1,prev,nums);
        int take=0;
        if(prev==-1 || nums[prev]<nums[i]){
            take = 1 + solve(i+1,i,nums);
        }
        return dp[i][prev+1]=max(take,nottake);
    }
    //memo

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums);
    }
};
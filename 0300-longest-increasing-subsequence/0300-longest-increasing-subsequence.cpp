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

    // int dp[2503][2503];
    // int solve(int i,int prev,vector<int>&nums){
    //     if(i==nums.size()) return 0;
    //     if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    //     int nottake = solve(i+1,prev,nums);
    //     int take=0;
    //     if(prev==-1 || nums[prev]<nums[i]){
    //         take = 1 + solve(i+1,i,nums);
    //     }
    //     return dp[i][prev+1]=max(take,nottake);
    // }
    //memo

    int solve(int n, vector<int>& nums) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = -1; prev < n; prev++) {
                int col = prev + 1;
                int nottake = dp[i + 1][col]; 
                int take = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + dp[i + 1][i + 1];  
                }
                dp[i][col] = max(take, nottake);
            }
        }
        return dp[0][0];
    }
    

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(n,nums);
        // return solve(0,-1,nums);
    }
};
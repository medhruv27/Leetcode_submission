class Solution {
public:
    int maxi=0;
    const int MOD = 1e9 +7;
    int solve(int i,vector<vector<int>>&dp,vector<int>&nums,int sum,int& m){
        if(i<0){
            cout<<sum<<endl;
            return (sum%3==0)?0:INT_MIN;
        }
        int take = (sum+nums[i])%3;
        int notake = sum%3;
        if(dp[i][sum]!=-1) return dp[i][sum];
        m++;
        return dp[i][sum]  = max(nums[i] + solve(i-1,dp,nums,take,m)  ,  solve(i-1,dp,nums,notake,m));
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        int m =0;
        return solve(n-1,dp,nums,0,m);
    }
};
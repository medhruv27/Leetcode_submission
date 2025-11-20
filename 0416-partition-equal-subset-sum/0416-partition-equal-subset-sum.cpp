class Solution {
public:
    bool Subsetsum(vector<int>&nums , int k ,int n){
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i =0;i<=n;i++){
             dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(nums[i-1]<=j){
                    dp[i][j]= dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][k];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n =nums.size();
        for(int i =0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0){
            return false;
        }
         else
        return Subsetsum(nums,sum/2 ,n);
    }
};
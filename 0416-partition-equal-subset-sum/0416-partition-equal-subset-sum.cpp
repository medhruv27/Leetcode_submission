class Solution {
public:
    // bool ss(vector<int>nums , int sum , int n){
    //     if(sum == 0) return true; 
    //     if(n == 0 ) return false;
    //     if(sum >= nums[n-1]){
    //         return (ss(nums , sum - nums[n-1] , n-1) || ss(nums , sum , n-1));
    //     }
    //     else{
    //         return ss(nums , sum , n-1);
    //     }
    // }
    bool ss(vector<int>&nums,int w,int n){
        vector<vector<int>>dp(n+1,vector<int>(w+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 != 0) return false;
        return ss(nums , sum/2 , nums.size());
    }
};
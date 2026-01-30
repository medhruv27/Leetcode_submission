class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int curr = dp[i];
            int steps = nums[i];
            for(int k=i+1;k<i+1+steps && k<n;k++){
                dp[k] = min(dp[k],curr + 1);
            }
        }
        return dp[n-1] ;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(n,0);
        int mini = prices[0];
        if(n==1) return 0;
        dp[0] = max(0,prices[1]-prices[0]);
        for(int i=1;i<n;i++){
            dp[i] = max(dp[i-1] , prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        return dp[n-1];
    }
};
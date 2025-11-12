class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);
        vector<int>dp(n+2,0);
        dp[1] = cost[0];
        for(int i=2;i<n+2;i++){
            dp[i] = cost[i-1]+ min(dp[i-1],dp[i-2]);
        }
        return dp[n+1];
    }
};
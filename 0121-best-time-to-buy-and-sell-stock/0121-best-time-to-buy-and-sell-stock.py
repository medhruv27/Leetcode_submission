class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp =[0] * n
        mini = prices[0]
        if(n<=1): 
            return 0
        dp[0] = max(0,prices[1]-prices[0])
        for i in range(1,n):
            dp[i] = max(dp[i-1] , prices[i]-mini)
            mini = min(mini,prices[i])
        return dp[n-1]
        
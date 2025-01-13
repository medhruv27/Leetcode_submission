class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, vector<int> coins) {
        if (i == 0)
            return INT_MAX - 1;
        if (j == 0)
            return 0;
        if (i == 1) {
            if (j % coins[0] == 0) {
                return j / coins[0];
            } else {
                return INT_MAX - 1;
            }
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (coins[i - 1] <= j) {
            dp[i][j] = min(solve(i, j - coins[i - 1], dp, coins) + 1, solve(i - 1, j, dp, coins));
        } else {
            dp[i][j] = solve(i - 1, j, dp, coins);
        }
        return dp[i][j];
    }
    int coinChange(vector<int>& coins, int w) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
        int ans = solve(n, w, dp, coins);
        if (ans >= INT_MAX - 1) {
            return -1;
        }
        return ans;

        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<w+1;j++){
        //         if(j==0){
        //             dp[i][j] =0;
        //         }
        //         if(i==0 ){
        //             dp[i][j]=INT_MAX-1;
        //         }
        //     }
        // }
        // for(int j=1;j<w+1;j++){
        //     if(j%coins[0] ==0){
        //         dp[1][j] = j/coins[0];
        //     }
        //     else{
        //         dp[1][j] = INT_MAX-1;
        //     }
        // }
        // for(int i=2;i<n+1;i++){
        //     for(int j=1;j<w+1;j++){
        //         if(coins[i-1] <=j){
        //             dp[i][j]= min(dp[i][j-coins[i-1]] +1, dp[i-1][j]);
        //         }
        //         else{
        //             dp[i][j] = dp[i-1][j];
        //         }
        //     }
        // }
        // if(dp[n][w]>= INT_MAX-1){
        //     return -1;
        // }
        //     return dp[n][w];
    }
};
class Solution {
public:
    // int solve(vector<int>&coins,int n,int w){
    //     if(w==0) return 0;
    //     if(n==0) return INT_MAX-1;
    //     if(n==1){
    //         if(w%coins[0]==0){
    //             return w/coins[0];
    //         }else{
    //             return INT_MAX-1;
    //         }
    //     }
    //     if(coins[n-1]<=w){
    //         return min(solve(coins,n,w-coins[n-1])+1,solve(coins,n-1,w));
    //     }else{
    //         return solve(coins,n-1,w);
    //     }
    // }
    //recu

    int dp[13][10001];
    int solve(vector<int>&coins,int n,int w){
        if(w==0) return 0;
        if(n==0) return INT_MAX-1;
        if(n==1){
            if(w%coins[0]==0){
                return w/coins[0];
            }else{
                return INT_MAX-1;
            }
        }
        if(dp[n][w]!=-1){
            return dp[n][w];
        }
        if(coins[n-1]<=w){
            return dp[n][w] = min(solve(coins,n,w-coins[n-1])+1,solve(coins,n-1,w));
        }else{
            return dp[n][w] = solve(coins,n-1,w);
        }
    }
    //memo

    int coinChange(vector<int>& coins, int w) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(coins,n,w);
        return ans==INT_MAX-1?-1:ans;
    }
};
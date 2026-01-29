class Solution {
public:
    int dp[500003][2];
    int solve(int i,int a,vector<int>&p,int n,int fee){
        if(i==n) return 0;
        if(dp[i][a]!=-1) return dp[i][a];
        if(a==1){
            return dp[i][a] = max(-p[i] + solve(i+1,0,p,n,fee), 0 + solve(i+1,1,p,n,fee));
        }else{
            return dp[i][a] = max(p[i] + solve(i+1,1,p,n,fee) - fee, 0 + solve(i+1,0,p,n,fee));
        }
    }
    int maxProfit(vector<int>& p, int fee) {
        //memo
        int n = p.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,1,p,n,fee);
    }
};
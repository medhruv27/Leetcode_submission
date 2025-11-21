class Solution {
public:
    int dp[1002][2][102];
    int f(int i,int a,int k,vector<int>&p,int n){
        if(k==0) return 0;
        if(i==n) return 0;
        if(dp[i][a][k]!=-1) return dp[i][a][k];
        if(a==1){
            return dp[i][a][k] = max(-p[i] + f(i+1,0,k,p,n), 0 + f(i+1,1,k,p,n));
        }else{
            return dp[i][a][k] = max(p[i] + f(i+1,1,k-1,p,n), 0 + f(i+1,0,k,p,n));
        }
    }
    int maxProfit(int k, vector<int>& p) {
        //memo
        int n = p.size();
        memset(dp,-1,sizeof(dp));
        return f(0,1,k,p,n);
    }
};
class Solution {
public:
    int dp[30001][3];
    // int solve(int i,int a,int n,vector<int>&p){
    //     //recursive soln
    //     // base condn
    //     if(i==n){
    //         return 0;
    //     }
    //     if(a==1){
    //         //buy it 
    //         return max(-p[i] + solve(i+1,0,n,p),0 + solve(i+1,1,n,p));
    //     }else{
    //         return max(p[i] + solve(i+1,1,n,p),0 + solve(i+1,0,n,p));
    //     }
    // }

    int solve(int i,int a,int n,vector<int>&p){
        //memo soln
        // base condn
        if(i==n){
            return 0;
        }
        if(dp[i][a]!=-1){
            return dp[i][a];
        }
        if(a==1){
            //buy it 
            return dp[i][a] = max(-p[i] + solve(i+1,0,n,p),0 + solve(i+1,1,n,p));
        }else{
            return dp[i][a] = max(p[i] + solve(i+1,1,n,p),0 + solve(i+1,0,n,p));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,1,n,prices);
    }
};
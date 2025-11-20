class Solution {
public:
    // int solve(int n,int w,string& t1,string& t2){
    //     if(n==0 || w==0){ return 0; }
    //     int take =0;
    //     if(t1[n-1]==t2[w-1]){
    //         take  = 1 + solve(n-1,w-1,t1,t2);
    //     }
    //     int notake = max(solve(n-1,w,t1,t2),solve(n,w-1,t1,t2));
    //     return max(take,notake);
        
    // }
    // recursive

    // int dp[1002][1002];
    // int solve(int i,int j,string t1,string t2){
    //     if(i==0 || j==0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int take = 0;
    //     if(t1[i-1]==t2[j-1]){
    //          take = 1 + solve(i-1,j-1,t1,t2);
    //     }
    //     int nottake = max(solve(i-1,j,t1,t2),solve(i,j-1,t1,t2));
    //     return dp[i][j] = max(take,nottake);
    // }
    //memo

    int solve(int n,int w, string& t1,string& t2){
        vector<vector<int>>dp(n+1,vector<int>(w+1,0));
        //base satisfied
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                int take =0;
                if(t1[i-1]==t2[j-1]){
                    take = 1 + dp[i-1][j-1];
                }
                int notake = max(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = max(take,notake);
            }
        }
        return dp[n][w];
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        
        // memset(dp,-1,sizeof(dp));
        return solve(n,m,t1,t2);
    }
};
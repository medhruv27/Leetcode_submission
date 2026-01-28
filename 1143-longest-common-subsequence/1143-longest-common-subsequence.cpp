class Solution {
public:
    // int solve(int n,int w,string& s1, string& s2){
    //     if(n==0 || w==0){
    //         return 0;
    //     }
    //     if(s1[n-1]==s2[w-1]){
    //         return 1 + solve(n-1,w-1,s1,s2);
    //     }
    //     return max(solve(n,w-1,s1,s2),solve(n-1,w,s1,s2));
    // }
    //recu

    int dp[1001][1001];
    // int solve(int n,int w,string& s1, string& s2){
    //     if(n==0 || w==0){
    //         return 0;
    //     }
    //     if(dp[n][w]!=-1){
    //         return dp[n][w];
    //     }
    //     if(s1[n-1]==s2[w-1]){
    //         return dp[n][w] = 1 + solve(n-1,w-1,s1,s2);
    //     }
    //     return dp[n][w] = max(solve(n,w-1,s1,s2),solve(n-1,w,s1,s2));
    // }
    //memo

    int solve(int n,int w,string& s1, string& s2){
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<=w;j++){
            dp[0][j] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][w];
    }

    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int w = t2.size();
        memset(dp,-1,sizeof(dp));
        return solve(n,w,t1,t2);
    }
};
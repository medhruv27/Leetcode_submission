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
    int solve(int n,int w,string& s1, string& s2){
        if(n==0 || w==0){
            return 0;
        }
        if(dp[n][w]!=-1){
            return dp[n][w];
        }
        if(s1[n-1]==s2[w-1]){
            return dp[n][w] = 1 + solve(n-1,w-1,s1,s2);
        }
        return dp[n][w] = max(solve(n,w-1,s1,s2),solve(n-1,w,s1,s2));
    }
    //memo

    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int w = t2.size();
        memset(dp,-1,sizeof(dp));
        return solve(n,w,t1,t2);
    }
};
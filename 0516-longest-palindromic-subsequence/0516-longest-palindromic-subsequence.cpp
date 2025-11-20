class Solution {
public:
    int dp[1002][1002];
    int solve(int n,int m,string& s,string& t){
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==t[m-1]){
            return dp[n][m] = 1 + solve(n-1,m-1,s,t);
        }
        else{
            return dp[n][m] = max(solve(n-1,m,s,t),solve(n,m-1,s,t));
        }
    }
    int longestPalindromeSubseq(string s) {
        string t =s;
        reverse(t.begin(),t.end());
        int n = s.length();
        int m =n;
        memset(dp,-1,sizeof(dp));
        return solve(n,m,s,t);
    }
};
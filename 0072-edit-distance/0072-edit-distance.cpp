class Solution {
public:
    int solve(int n,int m,string& s,string& t,vector<vector<int>>&dp){
        if(n==0 || m==0) return max(n,m);
        if(n==0 && m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==t[m-1]){
          dp[n][m] = solve(n-1,m-1,s,t,dp);
        }
        else{
          dp[n][m] = 1+min( {solve(n-1,m-1,s,t,dp),solve(n,m-1,s,t,dp) , solve(n-1,m,s,t,dp)});
        }
        return dp[n][m];
    }
    int minDistance(string s, string t) {
        int n= s.length();
        int m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,s,t,dp);
    }
};
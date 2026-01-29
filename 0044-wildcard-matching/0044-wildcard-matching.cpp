class Solution {
public:
    bool solve(int n ,int m, string &s,string &p,vector<vector<int>>&dp){
        if(n==0 && m==0)return true;
        if(n==0){
            for(int i=0;i<m;i++){
                if(p[i]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(m==0) return false;
        if (dp[n][m] != -1) return dp[n][m];
        if(s[n-1] == p[m-1] || p[m-1]=='?'){
         return dp[n][m] =  solve(n-1,m-1,s,p,dp);
        }
        if(p[m-1]== '*'){
            return dp[n][m] =  solve(n-1,m,s,p,dp) || solve(n,m-1,s,p,dp);
        }
        return false;

    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,s,p,dp);
    }
};
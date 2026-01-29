class Solution {
public:
    int dp[2001][2001];
    int solve(int n,int m,string &s,string &p){
        if(n==0 && m==0) return 1;
        if(n==0){
            for(int i=0;i<m;i++){
                if(p[i]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(m==0) return false;
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(p[m-1]=='*'){
            return dp[n][m] =  solve(n-1,m,s,p) || solve(n,m-1,s,p);
        }
        if((s[n-1]==p[m-1]) || p[m-1]=='?'){
            return dp[n][m] = (solve(n-1,m-1,s,p))?1:0;
        }
        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        memset(dp,-1,sizeof(dp));
        return solve(n,m,s,p);
    }
};
class Solution {
public:
    int count(int m,int n, vector<vector<int>>&dp){
        if(m==0 && n==0){
            return 1;
        }
        if(m <0 || n<0 ) return 0;
        if(dp[m][n]!=-1) return dp[m][n];

        return  dp[m][n] = count(m-1,n,dp) + count(m,n-1,dp);;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n, -1));
        return count(m-1,n-1,dp);
    }
};
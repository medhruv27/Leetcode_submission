class Solution {
public:
    const int MOD = 1000000007;
    int solve(int r,int c,vector<vector<vector<int>>>&dp,vector<vector<int>>&g,int sum,int k){
        if(r<0 || c<0){
            return 0;
        }
        if(r==0 && c==0){
            sum = (sum+g[0][0])%k;
            cout<<sum<<endl;
            return (sum%k==0)?1:0;
        }
        sum = (sum + g[r][c])%k;
        if(dp[r][c][sum]!=-1) 
            return dp[r][c][sum];
        long long left  = solve(r,c-1,dp,g,sum,k);
        long long up = solve(r-1,c,dp,g,sum,k);
        return dp[r][c][sum] = (left + up)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& g, int k) {
        int n = g.size(),m = g[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        int cnt = solve(n-1,m-1,dp,g,0,k);
        return cnt;
    }
};
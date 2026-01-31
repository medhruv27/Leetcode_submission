class Solution {
public:
    // int dp[102][102];
    // int solve(int i,int j,int m ,int n){
    //     if(i==m-1 || j==n-1){
    //         return 1;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     return dp[i][j] = solve(i+1,j,m,n) + solve(i,j+1,m,n);
    // }
    int uniquePaths(int m, int n) {
        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,m,n);
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                 if(i==0 && j==0) curr[0] = 1;
                 else{
                    int up=0,left =0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up+left;
                 }
            }
            prev = curr;
        }
      return prev[n-1];
    }
};
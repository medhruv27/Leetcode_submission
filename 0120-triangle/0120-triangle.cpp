class Solution {
public:
     int solve(int i,int j,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i>=m || j>=grid[i].size()){
            return INT_MAX;
        }
        if(i==m-1){
            return grid[i][j] ;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       return dp[i][j] =  grid[i][j] + min(solve(i+1,j,m,grid,dp),solve(i+1,j+1,m,grid,dp));
         
    }
    int minimumTotal(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return  solve(0,0,m,grid,dp) ;
    }
};
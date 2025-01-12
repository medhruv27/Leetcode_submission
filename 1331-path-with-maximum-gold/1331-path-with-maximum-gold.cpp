class Solution {
public:
    vector<int>lrow = {-1,0,1,0};
    vector<int>lcol = {0,1,0,-1};
    int dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        int curr = grid[i][j];
        grid[i][j]=0;
        int maxcoins = curr;
        for(int k=0;k<4;k++){
            int rn = i + lrow[k];
            int cn = j + lcol[k];
            if(rn>=0 && rn<n && cn>=0 && cn<m && grid[rn][cn]!=0){
               maxcoins = max(maxcoins,curr + dfs(grid,rn,cn,n,m));
            }
        }
        grid[i][j] = curr;
        return maxcoins;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi = max(maxi,dfs(grid,i,j,n,m));
            }
        }
        return maxi;
    }
};
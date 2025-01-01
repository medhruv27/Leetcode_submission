class Solution {
public:
    void dfs(vector<vector<int>>&vis,vector<vector<int>>&grid,int i,int j,int n,int m){
        int drow[] ={0,1,0,-1};
        int dcol[] ={1,0,-1,0};
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int rn = i + drow[k];
            int cn = j + dcol[k];
            if(rn>=0 && rn<n && cn>=0 && cn<m && vis[rn][cn]==0 && grid[rn][cn]==1){
                dfs(vis,grid,rn,cn,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(vis,grid,i,0,n,m);
            }
            if(grid[i][m-1]==1){
                dfs(vis,grid,i,m-1,n,m);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 ){
                dfs(vis,grid,0,j,n,m);
            }
            if(grid[n-1][j]==1){
                 dfs(vis,grid,n-1,j,n,m);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=grid[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
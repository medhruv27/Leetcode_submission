class Solution {
public:

    void dfs(int r ,int c,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int drow[] ={-1,0,1,0};
        int dcol[] ={0,1,0,-1};  
        int n = grid.size();
        int m = grid[0].size();         
        vis[r][c] = 1;
        for(int i=0;i<4;i++){
            int rn = r+ drow[i];
            int cn = c+ dcol[i];
            if(rn>=0 && rn<n && cn>=0 && cn<m && !vis[rn][cn] && grid[rn][cn] == 1){
                grid[rn][cn] = 0;
                dfs(rn,cn,vis,grid);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,vis,grid);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,vis,grid);
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    c++;
                }
            }
        }
        return c;
    }
};
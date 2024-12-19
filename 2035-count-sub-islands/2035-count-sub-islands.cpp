class Solution {
public:
bool bfs(int r ,int c, vector<vector<int>>&vis2 , vector<vector<int>>&grid,vector<vector<int>>&vis){
        queue<pair<int,int>>q;
        int drow[] ={-1,0,1,0};
        int dcol[] ={0,1,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        bool isSubIsland = true;
        vis2[r][c]=1;
        q.push({r,c});
        while(!q.empty()){
             int row = q.front().first;
             int col = q.front().second;
             q.pop();
             for(int i=0;i<4;i++){
                    int rn = row + drow[i];
                    int cn = col + dcol[i];
                    if( rn>=0 &&rn<n && cn>=0 && cn<m && !vis2[rn][cn] && grid[rn][cn]== 1){
                        vis2[rn][cn] =1;
                        if(vis[rn][cn]==0) isSubIsland = false;
                        q.push({rn,cn});
                    }
                
            }
        }
        return isSubIsland;
      
    }
    int countSubIslands(vector<vector<int>>& vis, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis2(n,vector<int>(m,0));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis2[i][j] && grid[i][j]== 1 && vis[i][j]==1){
                    if(bfs(i,j,vis2,grid,vis)) c++;
                }
            }
        }
        return c;
    }
};
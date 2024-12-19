class Solution {
public:
int bfs(int r ,int c, vector<vector<int>>&vis , vector<vector<int>>&grid,int cnt){
        queue<pair<int,int>>q;
        int drow[] ={-1,0,1,0};
        int dcol[] ={0,1,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        vis[r][c]=1;
        cnt++;
        q.push({r,c});
        while(!q.empty()){
             int row = q.front().first;
             int col = q.front().second;
             q.pop();
             for(int i=0;i<4;i++){
                    int rn = row + drow[i];
                    int cn = col + dcol[i];
                    if( rn>=0 &&rn<n && cn>=0 && cn<m && !vis[rn][cn] && grid[rn][cn]== 1 ){
                        vis[rn][cn] =1;
                        cnt++;
                        q.push({rn,cn});
                    }
                
            }
        }
        return cnt;
      
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
          int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cmax=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]== 1){
                    int c = bfs(i,j,vis,grid,0);
                    cmax = max(c,cmax);
                }
            }
        }
        return cmax;
    }
};
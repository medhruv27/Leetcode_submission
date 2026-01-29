class Solution {
public:
    int vis[301][301];
    void bfs(int sr,int sc,int r,int c, vector<vector<char>>&g){
        if(g[sr][sc]=='0'){
            return;
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr = sr + drow[i];
            int nc = sc + dcol[i];
            if(nr>=0 && nc>=0 && nr<r && nc < c && vis[nr][nc]==0 && g[nr][nc]=='1'){
                vis[nr][nc] =1;
                bfs(nr,nc,r,c,g);
            }
        }

    }
    int numIslands(vector<vector<char>>& g) {
        int r = g.size();
        int c = g[0].size();
        int cnt =0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis[i][j]==0 && g[i][j]=='1'){
                    cnt++;
                    vis[i][j] =1;
                    bfs(i,j,r,c,g);
                }
            }
        }
        return cnt;
    }
};
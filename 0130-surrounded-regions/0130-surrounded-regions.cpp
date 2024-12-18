class Solution {
public:

    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&board){
        int drow[] ={-1,0,1,0};
        int dcol[] ={0,1,0,-1};
         vis[r][c] =1;
         int n = board.size();
         int m = board[0].size();
         for(int i=0;i<4;i++){
            int rn = r + drow[i];
            int cn = c + dcol[i];
            if(rn>=0 && rn<n && cn>=0 && cn<m && vis[rn][cn]!=1 && board[rn][cn]=='O')
          {  dfs(rn,cn,vis,board);}
         }
    }
    void solve(vector<vector<char>>& board) {
       int n = board.size();
       if(n==0){return;}
       int m = board[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board);   
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board);
            }
       }
       for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
       }
      for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
      }
    }
};
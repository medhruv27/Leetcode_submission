class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j] =1;
                    q.push({{i,j},0});
                }
            }
        }
        int drow[] ={-1,0,1,0};
        int dcol[] ={0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[r][c] =steps;
            for(int i=0;i<4;i++){
                int rn = r + drow[i];
                int cn = c + dcol[i];
                if(rn>=0 && rn<n && cn>=0 && cn<m && vis[rn][cn]!=1){
                    vis[rn][cn] = 1;
                    q.push({{rn,cn},steps+1});
                }
            }
        }
        return dis;
    }
};
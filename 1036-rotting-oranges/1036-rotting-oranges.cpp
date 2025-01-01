class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int qsize = q.size();
        int tmax = INT_MIN;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            int drow[] = {0,1,0,-1};
            int dcol[] = {1,0,-1,0};
            for(int i=0;i<4;i++){
                int rn = r + drow[i];
                int cn = c + dcol[i];
                if(rn>=0 && rn<n && cn>=0 && cn<m && grid[rn][cn]==1){
                    grid[rn][cn] = 2;
                    q.push({{rn,cn},t+1});
                }
                tmax = max(t,tmax);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
                if(qsize==0) return 0;

      return tmax;
    }
};
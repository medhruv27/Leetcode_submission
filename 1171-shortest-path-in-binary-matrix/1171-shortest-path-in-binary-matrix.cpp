class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]==1) return -1;
        if(n==1 && grid[0][0]==0) return 1;
        // if(n==0) return 0;
        q.push({1,{0,0}});
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        while(!q.empty()){
            auto it = q.front();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();
            dis[r][c] = d;
            for(int drow =-1;drow<=1;drow++){
                for(int dcol=-1;dcol<=1;dcol++){
                    int rn = r + drow;
                    int cn = c + dcol;
                    if(rn>=0 && rn<n && cn>=0 && cn<n && grid[rn][cn]==0 && d + 1 < dis[rn][cn]){
                        dis[rn][cn] = 1 + d;
                        if(rn == n-1 && cn ==n-1){
                            return d + 1;
                        }
                        q.push({d+1,{rn,cn}});
                    }
                }
            }
        }
        return -1;
    }
};
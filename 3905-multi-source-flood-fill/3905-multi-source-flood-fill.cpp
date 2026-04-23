class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>mat(n,vector<int>(m,0));
        sort(sources.begin(), sources.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    });
        queue<pair<pair<int,int>,int>>q;
        for(auto s : sources){
            int i = s[0];
            int j = s[1];
            int c = s[2];
            mat[i][j] = c;
            q.push({{i,j},c});
        }
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                int drow[4] = {-1,0,1,0};
                int dcol[4] = {0,1,0,-1};
                int row = q.front().first.first;
                int col = q.front().first.second;
                int c = q.front().second;
                for(int j=0;j<4;j++){
                    int nr = drow[j] + row;
                    int nc = dcol[j] + col;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 0){
                        mat[nr][nc] = c;
                        q.push({{nr,nc},c});
                    }
                }
                q.pop();
            }
        }
        return mat;
    }
};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int src = image[sr][sc];
        if (src == color) return image; 
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = color;
        while(!q.empty()){
            auto it = q.front();
            int r = it.first;
            int c = it.second;
            image[r][c] = color;
            q.pop();
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr = drow[i] + r;
                int nc = dcol[i] + c;
                if(nr>=0 && nc>=0 && nr<n && nc<m && image[nr][nc]==src){
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};
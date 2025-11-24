class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n  = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        priority_queue<tuple<int,int,int>, 
                       vector<tuple<int,int,int>>, 
                       greater<tuple<int,int,int>>> pq;
        int drow[]= {-1,0,1,0};
        int dcol[]= {0,1,0,-1};
        pq.push({0,0,0});
        while(!pq.empty()){
             auto node = pq.top();
             int diff = get<0>(node);
             int r = get<1>(node);
             int c = get<2>(node);
             pq.pop();
             if(r==n-1 && c == m-1) return diff;
             for(int i=0;i<4;i++){
                int rn  = r + drow[i];
                int cn  = c + dcol[i];
                if(rn>=0 && rn <n && cn >=0 && cn<m){
                    int difnew = max(abs(heights[rn][cn]-heights[r][c]),diff); 
                    if(difnew<dis[rn][cn]){
                        dis[rn][cn] = difnew;
                        pq.push({difnew,rn,cn});
                    }
                }
             }

        }
        return 0;
    }
};
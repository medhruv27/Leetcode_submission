class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dis(n,1e9);
        dis[src] =0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
              auto it = q.front();
              int stops = it.first;
              int node = it.second.first;
              int d =  it.second.second;
              q.pop();
            //   if(stops>k) continue;
              for(auto it : adj[node]){
                int adjn = it.first;
                int adjw = it.second;
                if(d+adjw < dis[adjn] && stops<=k){
                    dis[adjn] = d+adjw;
                    q.push({stops+1,{adjn,d+adjw}});
                }
              }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};
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
         int node = q.front().second.first;
         int wt = q.front().second.second;
         int stops = q.front().first;
         q.pop();
         for(auto it : adj[node]){
            int disnode = it.second;
            int adjn = it.first;
            if(wt + disnode<= dis[adjn] && stops<=k){
                dis[adjn] = wt + disnode;
                q.push({stops+1,{adjn,dis[adjn]}});
            }
         }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];

    }
};
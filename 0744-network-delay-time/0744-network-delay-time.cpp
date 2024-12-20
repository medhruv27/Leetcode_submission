class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dis(n+1,1e9);
        queue<pair<int,int>>q;
        q.push({k,0});
        dis[k] =0;
        while(!q.empty()){
            auto p = q.front();
            int node = p.first;
            int d = p.second;
            q.pop();
            for(auto it : adj[node]){
                if(d + it.second < dis[it.first]){
                    dis[it.first] = d + it.second ;
                    q.push({it.first,d + it.second});
                }
            }
        }
         int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dis[i] == 1e9) return -1;
            maxTime = max(maxTime, dis[i]);
        }

        return maxTime;
    }
};
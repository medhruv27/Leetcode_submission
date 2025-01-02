class Solution {
public:
    int timer = 0;
    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj, 
             vector<int>& tin, vector<int>& tlow, vector<vector<int>>& bridges) {
       vis[node]=1;
       tlow[node]=tin[node]=timer++;
       for(auto it : adj[node]){
          if(it==parent) continue; //skip
          if(!vis[it]){
             dfs(it, node, vis, adj, tin, tlow, bridges);
             tlow[node] = min(tlow[node],tlow[it]);
             if(tlow[it]>tin[node]){
                bridges.push_back({it,node});
             }
          }else{
             tlow[node] = min(tlow[node],tin[it]);
          }
       }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n); // Initialize adjacency list with size n
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> bridges;
        vector<int> tin(n, -1), tlow(n, -1), vis(n, 0);
        dfs(0, -1, vis, adj, tin, tlow, bridges);
        return bridges;
    }
};

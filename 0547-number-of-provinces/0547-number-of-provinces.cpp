class Solution {
public:
void dfs(int node,vector<int>&vis,vector<int> adj[]){
    vis[node] =1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int>adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                } 
            }
        }
        for(int i = 0; i < v; i++) {
        cout << "Adjacency list of vertex " << i << ": ";
        for(int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j];
            if(j < adj[i].size() - 1) cout << " -> ";
        }
        cout << endl;
        }
        vector<int>vis(v,0);
        int cnt =0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};
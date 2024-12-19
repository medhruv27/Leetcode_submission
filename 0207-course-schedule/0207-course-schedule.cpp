class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
            vector<int>indeg(V,0);
            vector<int> topo;
            for (int i = 0; i < V; i++) {
                for (auto it : adj[i]) {
                    indeg[it]++;
                }
            }
            queue<int> q;
            for (int i = 0; i < V; i++) {
                if (indeg[i] == 0) {
                    q.push(i);
                }
            }
            int c =0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                // topo.push_back(node);
                c++;
                for (auto it : adj[node]) {
                    indeg[it]--;
                    if (indeg[it] == 0) {
                        q.push(it);
                    }
                }
            }
            if(c==V){
                return true;
            }
            return false;
        }
    };
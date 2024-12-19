class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>adjrev[V];
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                adjrev[it].push_back(i);
            }
        }
        vector<int>indeg(V,0);
        for(int i=0;i<V;i++){
             for(auto it : adjrev[i]){
            indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adjrev[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
       sort(topo.begin(),topo.end());
       return topo;
    }
};
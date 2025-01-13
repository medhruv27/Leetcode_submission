class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& pre) {
        vector<int>adj[v];
        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indeg(v,0);
        for(int i =0;i<v;i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int c=0;
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            c++;
            topo.push_back(node);
            for(auto it : adj[node]){
              indeg[it]--;
              if(indeg[it]==0){
                q.push(it);
              }
            }
        }
        if(topo.size()==v){
            return topo;
        }
        return {};
    }
};
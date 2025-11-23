class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& pre) {
        vector<int>adj[v];
        for(auto it : pre){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>topo;
        vector<int>indeg(v,0);
        for(int i=0;i<v;i++){
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
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // topo.push_back(node);
            c++;
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(c==v){
            return true;
        }
        return false;
    }
};
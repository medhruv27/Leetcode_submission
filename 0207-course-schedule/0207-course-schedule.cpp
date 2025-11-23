class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& e) {

        vector<int>adj[v];
        for(int i=0;i<e.size();i++){
            int f = e[i][0];
            int s = e[i][1];
            adj[f].push_back(s);
        }
        vector<int>indeg(v,0);
        queue<int>q;
        for(int i=0;i<v;i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        for(int i=0;i<v;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int c =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            c++;
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        return c==v;

    }
};
class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        size.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int node){
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]); // path compression.
    }
    void unionByRank(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        // connect the smallest one to the largest one...
        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        // connect the smallest one to the largest one...
        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        DisjointSet ds(v);
        vector<int>adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1){
                    ds.unionBySize(i,j);
                } 
            }
        }
        int cnt =0;
        for(int i=0;i<v;i++){
            if(i == ds.parent[i]){
                cnt++;
            }
        }
        return cnt;
    }
};
class Disjoint{
public:
    vector<int>parent,size,rank; 
    Disjoint(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findpar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findpar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int up = findpar(u);
        int vp = findpar(v);
        if(up==vp) return ;
        if(rank[up]<rank[vp]){
            parent[up] = vp;
        }else if(rank[up]>rank[vp]){
            parent[vp] = up;
        }else{
            parent[vp] =up;
            rank[up]++;
        }
    }
    void unionbysize(int u,int v){
        int up = findpar(u);
        int vp = findpar(v);
        if(up==vp) return ;
        if(size[up]<size[vp]){
            parent[up] = vp;
            size[vp]+=size[up];
        }else{
            parent[vp] = up;
            size[up]+=size[vp];
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        Disjoint ds(v);
        vector<int>adj(v);
       for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1){
                    ds.unionbysize(i,j);
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
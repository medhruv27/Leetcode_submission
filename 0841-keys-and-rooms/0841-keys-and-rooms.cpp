class Solution {
public:
    void dfs(vector<int>&vis,int root,vector<vector<int>>& rooms,int n){
        vis[root] = 1;
        for(auto node : rooms[root]){
            if(!vis[node]){
                dfs(vis,node,rooms,n);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,0);
        dfs(vis,0,rooms,n);
        for(auto it :vis){
            if(it==false){
                return false;
            }
        }
        return true;
    }
};
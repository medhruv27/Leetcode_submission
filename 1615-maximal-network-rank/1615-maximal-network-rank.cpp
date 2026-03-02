class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<vector<int>,int>mp;
        for(auto it:roads){
            mp[it]++;
        }
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(auto it :roads){
                int f = it[0];
                int s = it[1];
                if(i==f || i==s){
                    indeg[i]++;
                }
            }
        }
        int res=-1;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                vector<int> check = {i,j};
                if(mp.find(check)!=mp.end() || mp.find({j,i})!=mp.end()){
                    res = max(res,indeg[i]+indeg[j]-1);
                }else{
                    res = max(res,indeg[i]+indeg[j]);
                }
            }
        }
        return res;
    }
};
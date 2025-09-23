class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            vector<int>ans;
            if(i==0){
                res.push_back({1});
                continue;
            }
            for(int j=0;j<=i;j++){
                if(i-1>0 && j-1>=0 && j<i){
                    int a = res[i-1][j-1]+res[i-1][j];
                    ans.push_back(a);
                }else{
                    ans.push_back(1);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};
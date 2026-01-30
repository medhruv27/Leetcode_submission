class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>&a,const vector<int>&b){
            int f1 = a[0],s1=a[1];
            int f2 = b[0],s2=b[1];
            if(f1!=f2){
                return f1<f2;
            }
            return s1<s2;
        }
    };
    vector<vector<int>> merge(vector<vector<int>>&p) {
        sort(p.begin(),p.end(),cmp());
        int n = p.size();
        vector<vector<int>>res;
        res.push_back(p[0]);
        for(int i=1;i<n;i++){
            int lindx = res.size()-1;
            if(res[lindx][1]>=p[i][0]){
                res[lindx][1] = max(p[i][1],res[lindx][1]);
            }else{
                res.push_back(p[i]);
            }
        }
        return res;
    }
};
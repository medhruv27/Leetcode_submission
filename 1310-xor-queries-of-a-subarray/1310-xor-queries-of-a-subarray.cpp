class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        int n = queries.size();
        vector<int>pre;
        pre.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            int a = arr[i]^pre[i-1];
            pre.push_back(a);
        }
        for(int i=0;i<n;i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int res = pre[right];
            if(left>0){
                res = pre[left-1]^pre[right];
            }
            ans.push_back(res);
        }
        return ans;
    }
};
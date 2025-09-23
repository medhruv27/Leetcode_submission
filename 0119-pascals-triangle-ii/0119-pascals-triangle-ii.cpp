class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int r = rowIndex +1;
        vector<int>ans;
        long long a=1;
        ans.push_back(1);
        for(int c=1;c<r;c++){
           a = a*(r-c);
           a = a/c;
           ans.push_back(a);
        }
        return ans;
    }
};
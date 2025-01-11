class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it : mp){
            if(mp[it.first]==1){
                return it.first;
            }
        }
        return 0;
    }
};
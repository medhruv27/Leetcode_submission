class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int w) {
        map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int rem  = w - nums[i];
            if(mp.find(rem)!=mp.end()){
                return {i,mp[rem]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};  
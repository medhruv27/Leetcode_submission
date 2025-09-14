class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int rem = target - nums[i];
            if(mp.find(rem)!=mp.end() && mp[rem]!=i ){
                return {i,mp[rem]};
            }
            mp[nums[i]] =i;
        }
        return {};
    }
};
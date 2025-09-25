class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0] =1;
        int pre_sum =0;
        int c =0;
        for(int i=0;i<nums.size();i++){
            pre_sum += nums[i];
            int remove = pre_sum -k;
            c += mp[remove];
            mp[pre_sum] += 1;
        }
        return c;
    }
};
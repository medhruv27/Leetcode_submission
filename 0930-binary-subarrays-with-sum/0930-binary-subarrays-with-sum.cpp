class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        mp[0] =1;
        int pre_sum =0;
        int c =0;
        for(int i=0;i<n;i++){
            pre_sum += nums[i]&1;
            int remove = pre_sum -k;
            c += mp[remove];
            mp[pre_sum] += 1;
        }
        return c;
    }
};
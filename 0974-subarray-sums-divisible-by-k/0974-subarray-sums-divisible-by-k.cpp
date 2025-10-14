class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int presum = 0, rem = 0;
        int c = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            presum += nums[i];
            rem = presum % k;
            if (rem < 0) {
                rem += k;
            }
            if (mp.find(rem) != mp.end()) {
                c += mp[rem];
            }
            mp[rem]++;
        }
        return c;
    }
};
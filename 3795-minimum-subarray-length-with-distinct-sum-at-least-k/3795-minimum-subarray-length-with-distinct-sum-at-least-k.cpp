class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        int s=0,e = 0;
        long long Sum = 0;
        unordered_map<int, int> mp;
        while(e < n) {
            if (mp[nums[e]] == 0) {
                Sum += nums[e];
            }
            mp[nums[e]]++;
            while (Sum >= k) {
                ans = min(ans, e - s + 1);
                mp[nums[s]]--;
                if (mp[nums[s]] == 0) {
                    Sum -= nums[s];
                }
                s++;
            }
            e++;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
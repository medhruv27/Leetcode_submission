class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) return nums;  // each element is its own average
        int n = nums.size();

        vector<int> res(n, -1);   // initialize with -1
        int windowSize = 2 * k + 1;
        if (n < windowSize) return res;  // not enough elements

        int l = 0, r = 0;
        long long sum = 0;  // use long long to avoid overflow
        while (r < n) {
            sum += nums[r];

            if (r - l + 1 == windowSize) { // valid window
                int center = l + k;
                res[center] = sum / windowSize;

                // Slide the window
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return res;
    }
};
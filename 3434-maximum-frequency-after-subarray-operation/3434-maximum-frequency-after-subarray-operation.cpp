#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int tK = 0;
        for (int num : nums) {
            if (num == k) tK++;
        }
        int maxgain = 0;
        for (int y= 1; y<= 50; ++y) {
            if (y== k) continue;
            int currentGain = 0;
            int lmaxi = 0;
            // y contributes +1, k contributes -1
            for (int num : nums) {
                if (num == y) {
                    currentGain++;
                } else if (num == k) {
                    currentGain--;
                }
                if (currentGain < 0) {
                    currentGain = 0;
                }
                
                lmaxi = max(lmaxi, currentGain);
            }
            maxgain = max(maxgain, lmaxi);
        }
        
        return tK + maxgain;
    }
};
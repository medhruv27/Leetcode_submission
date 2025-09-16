class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
        if (n == 1) return;
        int i = n - 2;
        //this loop will find the pivot point
        while (i >= 0 && nums[i] >= nums[i+1]) {
            i--;
            // 2765  2 is the breaking point 
           //i = 0;
        }
        if (i >= 0) {
            int j = n - 1;
            while (nums[i] >= nums[j]) j--;
            //Swap the considered element with next greater element in the subarray
            // 2 swaps with 5 
            //5762
            swap(nums[i], nums[j]);
            //Reverse the subarray
            reverse(nums.begin() + i + 1, nums.end());
            // reverse from 7 to 2 
            //5267
            return;
        } 
        reverse(nums.begin(), nums.end());
    }
};
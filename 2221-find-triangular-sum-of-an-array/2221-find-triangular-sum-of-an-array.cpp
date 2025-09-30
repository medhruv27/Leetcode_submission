class Solution {
public:
    vector<int> helper(vector<int>&nums){
        int m = nums.size();
        for(int i=0;i<m-1;i++){
            nums[i] = (nums[i] + nums[i+1])%10;
        }
        return nums;
    }
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums = helper(nums);
        }
        return nums[0];
    }
};
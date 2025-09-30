class Solution {
public:
    vector<int> helper(vector<int>&nums){
        int m = nums.size();
        vector<int>temp(m-1,0);
        for(int i=0;i<m-1;i++){
            temp[i] = (nums[i] + nums[i+1])%10;
        }
        return temp;
    }
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums = helper(nums);
        }
        return nums[0];
    }
};
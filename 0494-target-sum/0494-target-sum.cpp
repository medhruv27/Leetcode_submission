class Solution {
public:
    int solve(int n,int w,vector<int>&nums){
        if(w==0 && n==0) return 1;
        if(n==0) return 0;
        if(nums[n-1]<=w){
            return solve(n-1,w-nums[n-1],nums) + solve(n-1,w,nums);
        }
        else{
            return solve(n-1,w,nums);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum  = accumulate(nums.begin(),nums.end(),0);
        target = abs(target);
        if (sum < target || (target + sum) % 2 != 0) return 0;
        int w = (sum+target)/2;
        int n = nums.size();
        cout<<w;
        return solve(n,w,nums);
    }
};
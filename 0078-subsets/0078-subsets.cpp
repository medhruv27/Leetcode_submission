class Solution {
public:
    vector<vector<int>>res;
    void solve(int i,int n,vector<int>&nums,vector<int>ans){
        if(i==n){
            res.push_back(ans);
            return;
        }
        solve(i+1,n,nums,ans);
        ans.push_back(nums[i]);
        solve(i+1,n,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        solve(0,n,nums,{});
        return res;
    }
};
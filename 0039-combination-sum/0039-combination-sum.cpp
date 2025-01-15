class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,int n,vector<int>&nums,int target,vector<int>op){
        if(target==0){
            ans.push_back(op);
            return;
        }
        if(target<0 || i==n) return ;
        op.push_back(nums[i]);
        solve(i,n,nums,target-nums[i],op);
        op.pop_back();
        solve(i+1,n,nums,target,op);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>op;
        solve(0,n,candidates,target,op);
        return ans;
    }
};
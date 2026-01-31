class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, int n, vector<int>& nums, int target, vector<int> op) {
        if (target == 0) {
            ans.push_back(op);
            return;
        }
        if (target < 0 || i == n) return;
        
        op.push_back(nums[i]);
        solve(i+1, n, nums, target - nums[i], op);
        op.pop_back();
        while(i+1<n && nums[i]==nums[i+1]) i++;
        solve(i + 1, n, nums, target, op);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> op;
        sort(candidates.begin(),candidates.end());
        solve(0, n, candidates, target, op);
        return ans;
    }
};

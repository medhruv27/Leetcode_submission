class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n  = nums.size();
        int maxi = nums[0];
        int mini = nums[n-1];
        vector<int>m(n,0);
        for(int i=n-1;i>=0;i--){
            mini = min(nums[i],mini);
            m[i] = mini;
        }
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            mini = m[i];
            if(maxi-mini<=k){
                return i;
            }
        }
        return -1;
    }
};
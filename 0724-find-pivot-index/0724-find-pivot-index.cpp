class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>presum(n,0);
        int sum =0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            presum[i] = sum;
        }
        int lsum =0;
        int ans = -1;
        for(int i=n-1;i>=0;i--){
            lsum+= nums[i];
            if(lsum==presum[i]){
                ans = i;
            }
        }
        return ans;
    }
};
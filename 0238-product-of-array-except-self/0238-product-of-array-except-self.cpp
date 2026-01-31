class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>op(n,1);
        int pre =1,post=1;
        for(int i=0;i<n;i++){
            op[i] = pre;
            pre = pre* nums[i];
        }
        for(int i=n-1;i>=0;i--){
            op[i] = post* op[i]; 
            post = post * nums[i];
        }
        return op;
    }
};
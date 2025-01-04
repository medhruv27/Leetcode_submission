class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=0,n = nums.size(),ans=1,cnt=0;
        if(k<=1) return 0;
        while(r<n){
            ans*= nums[r];
            if(ans<k){
                cnt+= r-l+1;
                r++;
            }else{
                while(ans>=k){
                    ans/=nums[l];
                    l++;
                }
                cnt+= r-l+1;
                r++;
            }
        }
        return cnt;
    }
};
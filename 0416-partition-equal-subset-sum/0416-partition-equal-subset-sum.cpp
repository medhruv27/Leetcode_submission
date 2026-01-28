class Solution {
public:
    bool ss(vector<int>&nums,int n,int w){
        if(n==0){
            return (w==0)?1:0;
        }
        if(w==0){
            return 1;
        }
        if(nums[n-1]<=w){// can take 
            return (ss(nums,n-1,w-nums[n-1]) || ss(nums,n-1,w))?1:0;
        }else{
            return ss(nums,n-1,w);
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 != 0) return false;
        return ss(nums , nums.size(), sum/2);
    }
};
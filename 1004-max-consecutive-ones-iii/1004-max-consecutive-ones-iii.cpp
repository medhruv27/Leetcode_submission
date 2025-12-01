class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int s =0;
        int e =0;
        int n = nums.size();
        int maxi=0;
        while(e<n){
            if(nums[e]==0){
                k--;
            }
            if(k>0){
                maxi = max(maxi,e-s+1);
                e++;
            }
            else if(k==0){
                maxi = max(maxi,e-s+1);
                e++;
            }
            else{
                while(k<0){
                    if(nums[s]==0){
                        k++;
                    }
                    s++;
                }
                e++;
            }
        }
        return maxi;
    }
};
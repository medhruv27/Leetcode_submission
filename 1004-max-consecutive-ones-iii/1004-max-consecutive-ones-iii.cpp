class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int s =0;
        int e =0;
        int n = nums.size();
        int maxi=0;
        int ans = 0;
        int cntk = k;
        while(e<n){
            if(nums[e]==0){
                cntk--;
            }else{
                ans++;
            }
            if(cntk>0){
                maxi = max(maxi,e-s+1);
                e++;
            }
            else if(cntk==0){
                maxi = max(maxi,e-s+1);
                e++;
            }
            else{
                while(cntk<0){
                    if(nums[s]==0){
                        cntk++;
                    }
                    s++;
                }
                e++;
            }
        }
        return maxi;
    }
};
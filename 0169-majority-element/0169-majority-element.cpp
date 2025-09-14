class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c =1;
        int ans = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==ans){
                c++;
                // ans = nums[i];
            }else{
                c--;
                if(c==0){
                ans = nums[i];
                c=1;
                }
            }
        }
        return ans;
    }
};
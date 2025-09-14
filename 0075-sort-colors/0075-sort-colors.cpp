class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0;
        int s=0;
        int e = nums.size()-1;
        while(a<=e){
            if(nums[a]==0){
                swap(nums[s],nums[a]);
                s++;
                a++;
            }
            else if(nums[a]==1){
                a++;
            }
            else{
                swap(nums[a],nums[e]);
                e--;
            }
        }
    }
};
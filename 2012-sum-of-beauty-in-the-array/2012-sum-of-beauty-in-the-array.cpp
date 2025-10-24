class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int>maxi;
        int n = nums.size();
        vector<int>mini(n,0);
        int max1 = nums[0];
        int min1 = nums[n-1];
        for(int i=0;i<n;i++){
            max1 = max(max1,nums[i]);
            maxi.push_back(max1);
        }
        for(int i =n-1;i>=0;i--){
            min1 = min(min1,nums[i]);
            mini[i] = min1;
        }
        int c =0;
        for(int i=1;i<n-1;i++){
            if(maxi[i-1]<nums[i] && nums[i]<mini[i+1]){
                c+=2;
            }else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                c++;
            }else{
                continue;
            }
        }
        return c;

    }
};
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        mp[0] =1;
        int pre_sum =0;
        int c =0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                nums[i] = 0;
            }else{
                nums[i] = 1;
            }
            pre_sum += nums[i];
            int remove = pre_sum -k;
            c += mp[remove];
            mp[pre_sum] += 1;
        }
        return c;

    }
};
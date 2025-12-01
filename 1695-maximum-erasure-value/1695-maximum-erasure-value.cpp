class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>mp;
        int s =0,e =0,n = nums.size();
        int sum =0,maxi = 0;
        while(e<n){
            mp[nums[e]]++;
            sum+=nums[e];
            if(mp.size()==(e-s+1)){
                //they are unique
                maxi = max(sum,maxi);
                e++;
            }
            else if(mp.size()<(e-s+1)){
                while(mp.size()<(e-s+1)){
                    sum-=nums[s];
                    mp[nums[s]]--;
                    if(mp[nums[s]]==0){
                        mp.erase(nums[s]);
                    }
                    s++;
                }
                e++;
            }
        }
        return maxi;
    }
};
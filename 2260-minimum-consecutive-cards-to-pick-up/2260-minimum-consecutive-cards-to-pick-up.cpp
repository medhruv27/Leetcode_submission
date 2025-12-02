class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
        int s =0,e =0,n= nums.size(),maxi=INT_MAX;
        map<int,int>mp;
        while(e<n){
            mp[nums[e]]++;
            if(mp[nums[e]]<2){
                e++;
            }else{
                 
                while(mp[nums[e]]>=2){
                    mp[nums[s]]--;
                    s++;
                }
                maxi = min(maxi,e-s+1+1);
                e++;
            }
        }
        return (maxi==INT_MAX)?-1:maxi;
    }
};
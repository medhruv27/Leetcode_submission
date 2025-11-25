class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int s =0,e=0,n = nums.size();
        map<int,int>mp;
        int res=0;
        while(e<n){
            mp[nums[e]]++;
            if(mp.size()<2) e++;
            if(mp.size()==2){
                res = max(res,e-s+1);
                e++;
            }
            else if(mp.size()>2){
                while(mp.size()>2){
                    mp[nums[s]]--;
                    if(mp[nums[s]]==0){
                        mp.erase(nums[s]);
                    }
                    s++;
                }
                e++;
            }
        }
        if(mp.size()<=1){
            for (auto it : mp){
                return it.second;
            }
        }
        return res;
    }
};
class Solution {
public:
    int countGoodSubstrings(string nums) {
        unordered_map<char,int>mp;
        int s=0,e=0;
        int cnt=0;
        while(e<nums.size()){
            int curr= nums[e];
            int prev= nums[s];
            mp[curr]++;
            int windowsize= e-s+1;
            if(windowsize<3){
                e++;
            }
            else if(windowsize==3){
                if(mp.size()==3){
                    cnt++;
                }
                mp[prev]--;
                if(mp[prev]==0){
                    mp.erase(prev);
                }
                s++;e++;
            }
        }
        return cnt;
    }
};
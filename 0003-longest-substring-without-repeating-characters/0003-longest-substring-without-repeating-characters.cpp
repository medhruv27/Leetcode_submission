class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        map<char,int>mp;
        int s = 0 ;
        int  e = 0;
        int n = str.size(),ans =0;
        while(e<n){
            mp[str[e]]++;
            if(mp.size()==e-s+1){
                //allunique
                ans = max(ans,e-s+1);
            }
            else if(mp.size()<e-s+1){
                while(mp.size()<e-s+1){
                    mp[str[s]]--;
                    if(mp[str[s]]==0){
                        mp.erase(str[s]);
                    }
                    s++;
                }
            }
            e++;
        }
        return ans;
    }
};
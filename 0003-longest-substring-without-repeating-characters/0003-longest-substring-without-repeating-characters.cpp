class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int s=0,e=0,n = str.length(),ans=0;
        map<char,int>mp;
        while(e<n){
            mp[str[e]]++;
            if(mp.size()>e-s+1){
                e++;
            }
            if(mp.size()==e-s+1){
                ans = max(ans,e-s+1);
                e++;
            }
            else if(mp.size()<e-s+1){
                while(mp.size()<e-s+1){
                    mp[str[s]]--;
                    if(mp[str[s]]==0){
                        mp.erase(str[s]);
                    }
                    s++;
                }
                e++;
            }
        }
        return ans;
    }
};
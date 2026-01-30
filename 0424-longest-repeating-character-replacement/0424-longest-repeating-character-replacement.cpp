class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0  , j =0  , ans =   0  ,n = s.length() ;
        unordered_map<char , int>mp ;
        int maxfreq = 0 ;

        while(j < n){
            mp[s[j]]++ ;
            maxfreq = max(maxfreq , mp[s[j]]) ;

            if(maxfreq + k >= j-i+1){
                ans = max(ans , j-i+1) ;
            }
            else if(maxfreq + k < j-i+1 ){
                while(maxfreq + k < j-i+1){
                    mp[s[i]]-- ;
                    i++ ;
                }
                ans =max(ans , j-i+1) ;
            }
            j++ ;
        }
        return ans ;
    }
};
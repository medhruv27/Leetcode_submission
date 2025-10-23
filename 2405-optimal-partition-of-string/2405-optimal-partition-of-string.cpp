class Solution {
public:
    int partitionString(string s) {
        map<int,int>mp;
        int n = s.length();
        int c =1;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]++;
            }
            else{
                mp.clear();
                mp[s[i]]++;
                c++;
            }
        }
        return c;
    }
};
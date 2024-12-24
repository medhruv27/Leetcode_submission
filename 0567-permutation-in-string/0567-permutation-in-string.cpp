class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      unordered_map<char,int>mp;
      int k = s1.size();
      for(int i=0;i<k;i++){
        mp[s1[i]]++;
      }        
      int s=0,e=0,cnt=0;
      int count = mp.size();
      while(e<s2.size()){
        int curr = s2[e];
        int prev = s2[s];
        if(mp.find(curr)!=mp.end()){
            mp[s2[e]]--;
            if(mp[curr]==0){
                count--;
            }
        }
        int windowsize = e-s+1;
        if(windowsize<k){
            e++;
        }
        else if(windowsize==k){
            if(count==0){
                return true;
            }
            if(mp.find(prev)!=mp.end()){
                mp[prev]++;
                if(mp[prev]==1){
                    count++;
                }
            }
            s++;e++;
        }
      }
      return false;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
        map<char,int>mp;
        for(int i=0;i<pat.size();i++){
            mp[pat[i]]++;
        }
        int s=0,e=0,n=pat.size(),count = mp.size();
        vector<int>ans;
        while(e<txt.size()){
            char end = txt[e];
            char front = txt[s];
            if(mp.find(end)!=mp.end()){
                mp[end]--;
                if(mp[end]==0){
                    count--;
                }
            }
            int ws = e-s+1;
            if(ws<n){
                e++;
            }else if(ws==n){
                if(count ==0){
                    ans.push_back(s);
                }
                if(mp.find(front)!=mp.end()){
                    mp[front]++;
                    if(mp[front]==1){
                        count++;
                    }
                }
                s++;e++;
            }
        }
        return ans;
    }
};
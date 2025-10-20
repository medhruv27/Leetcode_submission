class Solution {
public:
    string mini;
    void solve(int i,string res,string &target,vector<int>count){
        int n = target.size();
        if(i==n){
            if(res>target){
                mini = min(mini,res);
            }
            return;
        }
        if(count[target[i]-'a']>0){
            count[target[i]-'a']--;
            solve(i+1,res + target[i],target,count);
            count[target[i]-'a']++;
        }
        for(int j = target[i] - 'a' +1; j<26;j++){
            if(count[j]>0){
                res+= 'a' +j;
                count[j]--;
                for(int k=0;k<26;k++){
                    while(count[k]>0){
                        res+= 'a' +k;
                        count[k]--;
                    }
                }
                mini = min(mini,res);
                return;
            }
        }
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int>count(26,0);
        sort(s.rbegin(),s.rend());
        if(s<=target) return "";
        mini =s;
        for(auto it : s) count[it-'a']++;
        solve(0,"",target,count);
        return mini;
    }
};
class Solution {
public:
    vector<string>res;
    void solve(int i,int n,string s,string ans){
        if(i==n){
            res.push_back(ans);
            return ;
        }
        if(isalpha(s[i])){
            solve(i+1,n,s,ans + static_cast<char>(tolower(s[i])));
            solve(i+1,n,s,ans + static_cast<char>(toupper(s[i])));
        }else{
            solve(i+1,n,s,ans+ s[i]);
        }
    }
    vector<string> letterCasePermutation(string s) {
        int n = s.length();
        solve(0,n,s,"");
        return res;
    }
};
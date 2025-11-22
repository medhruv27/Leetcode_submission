class Solution {
public:
    vector<string>res;
    void solve(int n,string ans){
        if(n==0){
            res.push_back(ans);
            return;
        }
        if(ans.length()==0 || ans.back()=='1'){
            solve(n-1,ans + '1');
            solve(n-1,ans + '0');
        }
        else if(ans.back()=='0'){
            solve(n-1,ans + '1');
        }
    }
    vector<string> validStrings(int n) {
        string ans ="";
        solve(n,ans);
        return res;
    }
};